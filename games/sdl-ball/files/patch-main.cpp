--- main.cpp.orig	2018-05-14 18:46:05 UTC
+++ main.cpp
@@ -3762,7 +3762,7 @@ int main (int argc, char *argv[]) {
 
   difficulty = static_difficulty;
 
-  cout << "SDL-Ball v "VERSION << endl;
+  cout << "SDL-Ball v " VERSION << endl;
 
   // default to "" (If this have a 0 len after trying to getenv, it defaults to ./)
   privFile.programRoot = ""; 
