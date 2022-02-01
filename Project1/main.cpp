#include <math.h>
#include <iostream>
#include <stdbool.h>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

typedef std::string str;

void simple_tokenizer(str s, std::vector<str>& v) {
	std::stringstream ss(s);
	str word;
	while (ss >> word) {
		v.push_back(word);
	}
}

int _4d6kh3();
int d8();

typedef struct {
	int value;
	int modifier;
} charstat;

charstat genStat(int value);

enum class skills {
	melee,
	ranged,
	spellcaster,
	rogue
};

typedef struct {
	int hp;
	int ac;
	skills type;
	int level;

	charstat str;
	charstat dex;
	charstat con;
	charstat intel;
	charstat wis;
	charstat cha;
} character;

void printCharacter(character& c);

int main(void) {
	std::srand(std::time(0));

	const str escape = "";
	const str chargen = "char";
	str input = "missingno";
	
	while (true) {
		getline(std::cin, input);

		if (!escape.compare(input)) {
			break;
		}

		std::vector<str> vec;
		simple_tokenizer(input, vec);

		if (!chargen.compare(vec[0])) {
			int lvl = vec.size() > 1 ? stoi(vec[1]) : 1; // str to int
			int dump = std::rand() % 6;
			
			character generated;

			generated.str = genStat(_4d6kh3());
			generated.dex = genStat(_4d6kh3());
			generated.con = genStat(_4d6kh3());
			generated.intel = genStat(_4d6kh3());
			generated.wis = genStat(_4d6kh3());
			generated.cha = genStat(_4d6kh3());

			generated.type = skills(std::rand() & 3);
			generated.level = lvl;

			if (lvl >= 1) { // user input safety
				for (int i = 1; i <= lvl; i++) {
					//todo: level up
				}
			}

			printCharacter(generated);
		}
	}
}

int _4d6kh3() {
	int rolls[4];
	rolls[0] = (std::rand() % 6) + 1;
	rolls[1] = (std::rand() % 6) + 1;
	rolls[2] = (std::rand() % 6) + 1;
	rolls[3] = (std::rand() % 6) + 1;
	//std::cout << std::to_string(rolls[0]) + " " + std::to_string(rolls[1]) + " " + std::to_string(rolls[2]) + " " + std::to_string(rolls[3]) << " >> ";
	std::sort(rolls, rolls + 4);
	//std::cout << std::to_string(rolls[0]) + " " + std::to_string(rolls[1]) + " " + std::to_string(rolls[2]) + " " + std::to_string(rolls[3]) << std::endl;
	return rolls[1] + rolls[2] + rolls[3];
}

int d8() {
	return (std::rand() & 0x7) + 1;
}

charstat genStat(int value) {
	charstat result;
	result.value = value;
	result.modifier = floor(((double)value - 10.0) / 2.0);
	return result;
}

str stat2str(charstat val) {
	return std::to_string(val.value) + " (" + (val.modifier >= 0 ? "+": "") + std::to_string(val.modifier) + ")";
}

str skills2str(skills type) {
	switch (type) {
	case skills::melee:
		return "Melee";
	case skills::ranged:
		return "Ranged";
	case skills::spellcaster:
		return "Spellcaster";
	case skills::rogue:
		return "Rogue";
	default:
		return "Missingno";
	}
}

void printCharacter(character& c) {
	std::cout << "===================================================" << std::endl;
	std::cout << skills2str(c.type) << " " << c.level << " MaxHP: " << c.hp << " AC : " << c.ac << std::endl;
	std::cout << "Str: " << stat2str(c.str) << " Dex: " << stat2str(c.dex) << " Con: " << stat2str(c.con)
		<< " Int: " << stat2str(c.intel) << " Wis: " << stat2str(c.wis) << " Cha: " << stat2str(c.cha) << std::endl;
	std::cout << "===================================================" << std::endl;
}