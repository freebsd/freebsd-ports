--- kaptain/tools.h.orig	Wed Aug 14 12:17:34 2002
+++ kaptain/tools.h	Fri Dec 20 16:14:31 2002
@@ -3,20 +3,21 @@
 
 #include <list>
 #include <string>
+#include <iostream>
+#include <iterator>
 
-using namespace std;
 
 /**********/
 class Error
 {
-  list<string> messages;
+  std::list<std::string> messages;
   bool stop;
 
 public:
   Error();
 
-  void warning(string);
-  void error(string);
+  void warning(std::string);
+  void error(std::string);
 
   bool go_on() { return !stop; }
 
@@ -32,19 +33,19 @@
 public:
   Regexp();
 
-  static bool matches(string, string, list<string> & );
+  static bool matches(std::string, std::string, std::list<std::string> & );
 
-  static bool substitute_local(string, string, string, 
-                               string &, int &);
-  static void substitute(string, string, string, 
-                         string &, bool);
+  static bool substitute_local(std::string, std::string, std::string, 
+                               std::string &, int &);
+  static void substitute(std::string, std::string, std::string, 
+                         std::string &, bool);
 
-  static void transliterate(string, string,
-                            string, string &);
+  static void transliterate(std::string, std::string,
+                            std::string, std::string &);
 
-  static void split(char, string, list<string> &);
+  static void split(char, std::string, std::list<std::string> &);
 
-  static void join(char, list<string> &, string &);
+  static void join(char, std::list<std::string> &, std::string &);
 };
 
 
