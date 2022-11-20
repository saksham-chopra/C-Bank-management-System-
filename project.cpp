#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
struct Bank {
	string f_name, l_name, ph_no, address, cnic; int amount;
	Bank() :f_name(""), l_name(""), ph_no(""), address(""), cnic(""),amount(0) {}
	void welcome() {
		
		cout << "\t\t\t\t\t\tMy Banking System!\t\t\t\t\t\t" << endl;
	}
	//information of person
	void info() {
		cout << "Please enter your first name: "; cin >> f_name;
		cout << "Please enter your last name: "; cin >> l_name;
		cout << "Please enter your phone no.: "; cin >> ph_no;
		cout << "Please enter your address: "; cin >> address;
		cout << "Please enter your CNIC: "; cin >> cnic;
	}
	//displaying content
	void display() {
		cout << "Your first name: " << f_name << endl;
		cout << "Your last name: " << l_name << endl;
		cout << "Your phone no.: "<< ph_no << endl;
		cout << "Your address: " << address << endl;
		cout << "Your CNIC: " << cnic << endl;
		cout << "Your current amount is: " << amount << endl;
	}
};
int main() {
	int key;
	Bank b;
	do
	{
	b.welcome();
	cout << "Please select one option from below menu. \n";
c:	cout << "1. Account Open. \n2. Deposit Amount. \n3. Withdraw Amount. \n4. Check Balance. \n";
	cout << "5. Update Record. \n6. Delete Record. \n7. Search Record. \n8. Exit. \n";
		cin >> key;
		if (key == 1) //to open acc.
		{
			b.info();
			ofstream f("E:\\Bank Management\\Reg_users.dat",ios::app); //represent output file stream & used to create files
			f.write((char*)&b, sizeof(b)); // data write in file 
			f.close();
			b.display();
			Sleep(3000);
			system("cls"); //open up kinda new page "clearscreen".
		}
		else if (key == 2) { //to deposit amount.
			string nam; int am = 0,count=0;
			cout << "Please enter your first name: "; cin >> nam;
			ifstream u("E:\\Bank Management\\Reg_users.dat"); // represent input file stream & read data in file.
			while (u.read((char*)&b,sizeof(b)))
			{
				if (nam == b.f_name)
				{
					ofstream f("E:\\Bank Management\\Reg_users1.dat", ios::app);
					cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
					cout << "Current amount is: " << b.amount << endl;
					cout << "Please enter new amount: "; cin >> am;
					b.amount += am;
					cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
					cout << "Current amount is: " << b.amount << endl;
					f.write((char*)&b, sizeof(b));
					ifstream u("E:\\Bank Management\\Reg_users.dat");
					while (u.read((char*)&b, sizeof(b)))
					{
						if (nam != b.f_name)
						{
							f.write((char*)&b, sizeof(b));
						}
					}f.close(); count += 1;
				
				}
				else {
					cout << "Computer is either searching or wasn`t able to find your record. \n";
				}
			}Sleep(3000);
			system("cls");
			u.close();
			if (count >= 1)
			{
				remove("E:\\Bank Management\\Reg_users.dat");
				rename("E:\\Bank Management\\Reg_users1.dat", "E:\\Bank Management\\Reg_users.dat");
			}
		}
		else if (key == 3) { //withdraw amount.
			string nam; int am = 0,count = 0;
			cout << "Please enter your first name: "; cin >> nam;
			ifstream u("E:\\Bank Management\\Reg_users.dat");
			while (u.read((char*)&b, sizeof(b)))
			{
				if (nam == b.f_name)
				{
					ofstream f("E:\\Bank Management\\Reg_users1.dat", ios::app);
					cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
					cout << "Current amount is: " << b.amount << endl;
			a:		cout << "Please enter new amount: "; cin >> am;
					if (am < b.amount)
					{
						b.amount -= am;
					}
					else {
						cout << "Amount being withdrawn is more than amount avaiable in the account.\n";
						goto a;
					}
					cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
					cout << "Current amount is: " << b.amount << endl;
					f.write((char*)&b, sizeof(b));
					ifstream u("E:\\Bank Management\\Reg_users.dat");
					while (u.read((char*)&b, sizeof(b)))
					{
						if (nam != b.f_name)
						{
							f.write((char*)&b, sizeof(b));
						}
					}f.close(); count += 1;

				}
				else {
					cout << "Computer is either searching or wasn`t able to find your record. \n";
				}
			}Sleep(3000);
			system("cls");
			u.close();
			if (count >= 1)
			{
				remove("E:\\Bank Management\\Reg_users.dat");
				rename("E:\\Bank Management\\Reg_users1.dat", "E:\\Bank Management\\Reg_users.dat");
			}
		}
		else if (key == 4) { //check balaance.
			string nam;
			cout << "Please enter your first name: "; cin >> nam;
			ifstream u("E:\\Bank Management\\Reg_users.dat");
			while (u.read((char*)&b, sizeof(b)))
			{
				if (nam == b.f_name)
				{
					cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
					cout << "Current amount is: " << b.amount << endl;
				}
				else {
					cout << "Computer is either searching or wasn`t able to find your record. \n";
				}
			}Sleep(3000);
			system("cls");
			u.close();
		}
		else if(key == 5){ //update in file
		string nam; int count = 0; char ke, opt;
		cout << "Please enter your first name: "; cin >> nam;
		ifstream u("E:\\Bank Management\\Reg_users.dat");
		while (u.read((char*)&b, sizeof(b)))
		{
			if (nam == b.f_name)
			{
				b.display();
				cout << "=================================================================\n";
				ofstream f("E:\\Bank Management\\Reg_users1.dat", ios::app);
			b:	cout << "To update first name (Press f). \nTo update last name (Press l). \n";
				cout << "To update phone no. (Press p). \nTo update address (Press a). \nTo update cnic (Press c). \n";
				cin >> ke;
				if (ke == 'f') //keys for searching data
				{
					cout << "Please enter your new first name: "; cin >> b.f_name;
					f.write((char*)&b, sizeof(b));
					ifstream u("E:\\Bank Management\\Reg_users.dat");
					while (u.read((char*)&b, sizeof(b)))
					{
						if (nam != b.f_name)
						{
							f.write((char*)&b, sizeof(b));
						}
					}
				}
				else if (ke == 'l') {
					cout << "Please enter your new last name: "; cin >> b.l_name;
					f.write((char*)&b, sizeof(b));
					ifstream u("E:\\Bank Management\\Reg_users.dat");
					while (u.read((char*)&b, sizeof(b)))
					{
						if (nam != b.f_name)
						{
							f.write((char*)&b, sizeof(b));
						}
					}
				}
				else if (ke == 'p') {
					cout << "Please enter your new number: "; cin >> b.ph_no;
					f.write((char*)&b, sizeof(b));
					ifstream u("E:\\Bank Management\\Reg_users.dat");
					while (u.read((char*)&b, sizeof(b)))
					{
						if (nam != b.f_name)
						{
							f.write((char*)&b, sizeof(b));
						}
					}
				}
				else if (ke == 'a') {
					cout << "Please enter your new address: "; cin >> b.address;
					f.write((char*)&b, sizeof(b));
					ifstream u("E:\\Bank Management\\Reg_users.dat");
					while (u.read((char*)&b, sizeof(b)))
					{
						if (nam != b.f_name)
						{
							f.write((char*)&b, sizeof(b));
						}
					}
				}
				else if (ke == 'c') {
					cout << "Please enter your new CNIC: "; cin >> b.cnic;
					f.write((char*)&b, sizeof(b));
					ifstream u("E:\\Bank Management\\Reg_users.dat");
					while (u.read((char*)&b, sizeof(b)))
					{
						if (nam != b.f_name)
						{
							f.write((char*)&b, sizeof(b));
						}
					}
				}
				cout << "Do you want to update record again? (y/n) ";
				cin >> opt;
				if (opt == 'y')
				{
					goto b;
				}
				else {
					f.close(); count += 1;
				}
			}
			else {
				cout << "Computer is either searching or wasn`t able to find your record. \n";
			}
		}Sleep(3000);
		system("cls");
		u.close();
		if (count >= 1)
		{
			remove("E:\\Bank Management\\Reg_users.dat");
			rename("E:\\Bank Management\\Reg_users1.dat", "E:\\Bank Management\\Reg_users.dat"); // remove data not req nd rename it out.
		}
}
		else if (key == 6) { //delete account.
		string nam; int count = 0; char ke;
		cout << "Please enter your first name: "; cin >> nam;
		ifstream u("E:\\Bank Management\\Reg_users.dat");
		while (u.read((char*)&b, sizeof(b)))
		{
			if (nam == b.f_name)
			{
				ofstream f("E:\\Bank Management\\Reg_users1.dat", ios::app);
				cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
				cout << "Current amount is: " << b.amount << endl;
				cout << "Do you really want to delete the record? (y/n) ";
				cin >> ke;
				if (ke == 'y') //keys for yes & no.
				{
					ifstream u("E:\\Bank Management\\Reg_users.dat");
					while (u.read((char*)&b, sizeof(b)))
					{
						if (nam != b.f_name)
						{
							f.write((char*)&b, sizeof(b));
						}
					}
				}
				else {
					goto c;
				}
				f.close(); count += 1;

			}
			else {
				cout << "Computer is either searching or wasn`t able to find your record. \n";
			}
		}Sleep(3000);
		system("cls");
		u.close();
		if (count >= 1)
		{
			remove("E:\\Bank Management\\Reg_users.dat");
			rename("E:\\Bank Management\\Reg_users1.dat", "E:\\Bank Management\\Reg_users.dat");
		}
}
		else if (key == 7) { //search account in file
		string nam;
		cout << "Please enter your first name: "; cin >> nam;
		ifstream u("E:\\Bank Management\\Reg_users.dat");
		while (u.read((char*)&b, sizeof(b)))
		{
			if (nam == b.f_name)
			{
				b.display();
			}
			else {
				cout << "Computer is either searching or wasn`t able to find your record. \n";
			}
		}Sleep(5000);
		system("cls");
		u.close();
}
	} while (key != 8); //last exit
	system("cls");
	b.welcome();
	cout << "\t\t\t\t\t Thank You for visiting our bank. \n\t\t\t\t\t\t";
}
