--- src/highscore.cc.orig	Sat May  4 23:43:58 2002
+++ src/highscore.cc	Sun Oct 30 00:49:25 2005
@@ -17,27 +17,30 @@
  */
 
 #include <fstream.h>
+using namespace std;
 
 #include "highscore.h"
 
 void 
 HighScore::Read()
 {
-   std::string filename = getenv("HOME");
+   string filename = getenv("HOME");
    filename += "/.groundhog.highscore";
-   std::ifstream in(filename.c_str());
+   ifstream in(filename.c_str());
+   if (in==NULL)
+       return;
    in >> _beginner >> _intermediate >> _expert;
 }
 
 void 
 HighScore::Write()
 {
-   std::string filename = getenv("HOME");
+   string filename = getenv("HOME");
    filename += "/.groundhog.highscore";
-   std::ofstream out(filename.c_str());
-   out << _beginner << std::endl
-       << _intermediate << std::endl
-       << _expert << std::endl;
+   ofstream out(filename.c_str());
+   out << _beginner << endl
+       << _intermediate << endl
+       << _expert << endl;
 }
 
 
