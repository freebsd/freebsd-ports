--- ./src/FileIO/fileio.h.orig	Mon Jul 21 16:28:28 2003
+++ ./src/FileIO/fileio.h	Mon Jul 21 16:28:40 2003
@@ -8,7 +8,7 @@
 #include <stdio.h>
 
 #include <string>
-
+using std::string;
 
 string readString(FILE *f);
 void writeString(FILE *f, const string& s);
