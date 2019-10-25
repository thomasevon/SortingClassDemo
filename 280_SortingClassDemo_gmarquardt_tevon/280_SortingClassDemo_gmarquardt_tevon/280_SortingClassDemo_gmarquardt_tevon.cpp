/*
280
Sorting Class Demo
Gunnar Marquardt && Thomas Evon
*/
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

const int MAX_CHARS = 10;
const int MAX_STRINGS = 1000;

void cr(int n = 1) {
	for (int i = 0; i < n; i++)
		cout << endl;
} //cr

class Sorter {
private:
	string workspace[MAX_STRINGS];
	string randomString();
public:
	Sorter();
	void load();
	void display();
	void bubbleSort();
	bool isSorted();
};

Sorter::Sorter() { //there's nothing to do
}

string Sorter::randomString() {
	//pre:	none
	//post:	return a string of MAX_CHARS random lowercase characters
	string s = "";
	for (int i = 0; i < MAX_CHARS; i++) {
		char randomChar = char(rand() % 26 + 97);
		s += randomChar;
	}
	return s;
} //randomString

void Sorter::load() {
	//pre:	none
	//post:	workspace is loaded with random strings
	for (int i = 0; i < MAX_STRINGS; i++)
		workspace[i] = randomString();
} //load

void Sorter::display() {
	//pre:	none
	//post:	display workspace elements, separated by blanks
	//		for testing purposes with VERY small arrays
	for (int i = 0; i < MAX_STRINGS; i++)
		cout << workspace[i] << " ";
	cout << endl;
} //display

void Sorter::bubbleSort() {
	//pre:	none
	//post:	the workspace array is sorted in ascending order
	for (int pass = 0; pass < MAX_STRINGS - 1; pass++) {
		for (int pos = 0; pos < MAX_STRINGS - pass - 1; pos++) {
			if (workspace[pos] > workspace[pos + 1]) {
				string temp = workspace[pos];
				workspace[pos] = workspace[pos + 1];
				workspace[pos + 1] = temp;
			}
		}
	}
} //bubbleSort

bool Sorter::isSorted() {
	//pre:	none
	//post: returns true if the workspace is ascending sorted,
	//		false otherwise
	for (int i = 0; i < MAX_STRINGS - 1; i++)
		if (workspace[i] > workspace[i + 1])
			return false;
	return true;
} //isSorted

int main() {
	srand(time(NULL));
	clock_t start, stop;
	Sorter s1 = Sorter(); //use s1 with bubble sort
	s1.load();
	Sorter s2 = Sorter(s1); //use s2 with selection sort
	Sorter s3 = Sorter(s1); //use s3 with insertion sort
	Sorter s4 = Sorter(s1); //use s4 with shell sort
	Sorter s5 = Sorter(s1); //use s5 with quick sort

	//test bubble sort
	start = clock();
	s1.bubbleSort();
	stop = clock();
	//s1.display();
	if (!s1.isSorted()) {
		cout << "Error: bubble sort failed";
		cr(2);
		exit(EXIT_FAILURE);
	}
	else {
		double elapsedTime = ((double)stop - start) / CLOCKS_PER_SEC;
		cout << "Bubble sort time: " << elapsedTime << endl;
	}
	cr(2);

	//test selection sort

	//test insertion sort

	//test shell sort

	//test quick sort

}
