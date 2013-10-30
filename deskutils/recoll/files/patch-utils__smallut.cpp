--- ./utils/smallut.cpp.orig	2013-09-30 18:45:06.000000000 +0200
+++ ./utils/smallut.cpp	2013-10-29 15:57:51.000000000 +0100
@@ -34,8 +34,7 @@
 #include <string>
 #include <iostream>
 #include <list>
-#include <tr1/unordered_map>
-using std::tr1::unordered_map;
+#include "unordered_defs.h"
 using namespace std;
 
 #include "smallut.h"
@@ -1147,14 +1146,14 @@
 
 string langtocode(const string& lang)
 {
-    static unordered_map<string, string> lang_to_code;
+    static STD_UNORDERED_MAP<string, string> lang_to_code;
     if (lang_to_code.empty()) {
 	for (unsigned int i = 0; 
 	     i < sizeof(vlang_to_code) / sizeof(char *); i += 2) {
 	    lang_to_code[vlang_to_code[i]] = vlang_to_code[i+1];
 	}
     }
-    unordered_map<string,string>::const_iterator it = 
+    STD_UNORDERED_MAP<string,string>::const_iterator it = 
 	lang_to_code.find(lang);
 
     // Use cp1252 by default...
