--- src/highscore.cc/old	Sat May  4 23:43:58 2002
+++ src/highscore.cc	Thu May 23 14:10:49 2002
@@ -26,6 +26,8 @@
    std::string filename = getenv("HOME");
    filename += "/.groundhog.highscore";
    std::ifstream in(filename.c_str());
+   if (in==NULL)
+       return;
    in >> _beginner >> _intermediate >> _expert;
 }
 
