--- src/dos/cdrom_image.cpp.orig	Mon Oct 25 22:00:14 2004
+++ src/dos/cdrom_image.cpp	Mon Oct 25 22:00:52 2004
@@ -23,7 +23,7 @@
 #include <cstdio>
 #include <fstream>
 #include <iostream>
-#include <limits>
+/* #include <limits> */
 #include <sstream>
 #include <vector>
 #include <sys/stat.h>
@@ -572,7 +572,7 @@
 	if (stat(filename.c_str(), &test) == 0) return true;
 	
 	// check if file with path relative to cue file exists
-#if not defined(WIN32)
+#if !defined(WIN32)
 	string tmpstr(pathname + "/" + filename);
 	if (stat(tmpstr.c_str(), &test) == 0) {
 		filename = tmpstr;
