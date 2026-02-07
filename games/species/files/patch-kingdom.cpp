kingdom.cpp:149:19: error: assigning to 'bool' from incompatible type 'std::__1::fstream' (aka 'basic_fstream<char>')
        _in_experiment = fs;
                         ^~

--- kingdom.cpp.orig	2018-07-30 09:43:22 UTC
+++ kingdom.cpp
@@ -146,7 +146,7 @@ void CKingdom::load(const bool runnable) {
 	}
 	fs.clear();
 	fs.open("species.dat",ios::in|ios::binary); // open data file
-	_in_experiment = fs;
+	_in_experiment = fs.is_open();
 	if(!_in_experiment) { // couldn't open it?
 		if(verbose) {
 			cout << "species.dat failed; trying species.ini" << endl;
