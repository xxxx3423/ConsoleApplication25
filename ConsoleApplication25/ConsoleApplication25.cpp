#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Відкрити файл для зчитування вхідних даних
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    // Зчитати значення i
    int i;
    inputFile >> i;

    if (inputFile.fail()) {
        cerr << "Error reading input value." << endl;
        return 1;
    }

    // Перевірка обмежень для значення i
    if (i < 1 || i > 100) {
        cerr << "Input value out of range. It should be between 1 and 100." << endl;
        return 1;
    }

    // Обчислення кількості червоних та жовтих сигналів
    int red_count = 0;
    int yellow_count = 0;
    for (int cycle = 1; cycle <= i; ++cycle) {
        red_count++;
        yellow_count++;
        if (cycle < i) {
            yellow_count++;
        }
    }

    // Відкрити файл для запису вихідних даних
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    // Записати результати у файл
    outputFile << red_count << " " << yellow_count << endl;

    return 0;
}
