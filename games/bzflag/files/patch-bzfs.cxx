--- src/bzfs/bzfs.cxx.orig	Sat Nov 23 15:03:31 2002
+++ src/bzfs/bzfs.cxx	Sat Nov 23 15:03:45 2002
@@ -2805,7 +2805,7 @@
 static WorldInfo *defineWorldFromFile(const char *filename)
 {
   // open file
-  ifstream input(filename, ios::in | ios::nocreate);
+  ifstream input(filename, ios::in);
   if (!input) {
     cerr << "could not find bzflag world file : " << filename << endl;
     return NULL;
