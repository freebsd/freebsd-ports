--- src/MakeData.cpp.orig	2011-01-10 18:40:30.000000000 +0100
+++ src/MakeData.cpp	2012-05-03 20:21:33.000000000 +0200
@@ -4,7 +4,9 @@
 #include <cstdio>
 #define PNG_DEBUG 3
 #include <png.h>
+#include <pngpriv.h>
 #include <fstream>
+#include <sys/stat.h>
 #include "global.h"
 #include "Config.h"
 #include "Confirm.h"
@@ -376,7 +378,12 @@
 				}
 				fname[2]='0'+i; 
 				fname[1]='0'+j;
-				if (!f2->Save((dir+fname).c_str()))
+				size_t pos = 0;
+				do {
+					pos = dir.find('/', pos+1);
+					mkdir((home_dir+dir.substr(0, pos)).c_str(), 0755);
+				} while (pos != string::npos);
+				if (!f2->Save((home_dir+dir+fname).c_str()))
 					return false;
 				f2->width=ancho2; f2->height=ancho2;
 			}
