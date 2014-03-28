--- src/FDM/JSBSim/input_output/string_utilities.h.orig	2014-03-12 18:30:00.000000000 +0100
+++ src/FDM/JSBSim/input_output/string_utilities.h	2014-03-12 18:31:18.000000000 +0100
@@ -73,9 +73,11 @@
   extern bool is_number(const std::string& str);
   std::vector <std::string> split(std::string str, char d);
 /* Comment out to_string functions when they are defined already - C++ 11 defines these */
+/*
   extern std::string to_string(int);
   extern std::string to_string(double);
   extern std::string to_string(float);
+*/
   extern std::string replace(std::string str, const std::string& old, const std::string& newstr);
 #else
   #include <cctype>
@@ -159,6 +161,7 @@
     return str_array;
   }
 /* Comment out to_string functions when they are defined already - C++ 11 defines these */
+/*
   string to_string(int i)
   {
     char buffer[32];
@@ -179,6 +182,7 @@
     if (!(o << x)) cerr << "Bad double to string conversion" << endl;
     return o.str();
   }
+*/
 
   string replace(string str, const string& oldstr, const string& newstr)
   {
