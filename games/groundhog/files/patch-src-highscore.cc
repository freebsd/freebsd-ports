--- src/highscore.cc/old	Sat May  4 23:43:58 2002
+++ src/highscore.cc	Thu May 23 14:10:49 2002
@@ -26,6 +26,10 @@
    std::string filename = getenv("HOME");
    filename += "/.groundhog.highscore";
    std::ifstream in(filename.c_str());
+   if (in==NULL) {
+       cout << "Couldn't open highscore file (this is normal the first time the game is ran).\n";
+       return;
+   }
    in >> _beginner >> _intermediate >> _expert;
 }
 
