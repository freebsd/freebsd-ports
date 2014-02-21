--- bstring.cpp.orig	2014-02-21 15:40:03.760303112 -0500
+++ bstring.cpp	2014-02-21 15:41:19.474297650 -0500
@@ -15,7 +15,7 @@
 
 #include "bstring.h"
 #include <string.h>
-#include <fstream.h>
+#include <fstream>
 
 ///////////////////////////////////////***************************************
 
@@ -91,7 +91,7 @@
 
 b_string b_string::operator + (const char* s)
 {
-	b_string temp = str;
+	b_string temp (str);
 	return temp += s;
 }
 
@@ -217,4 +217,4 @@
 
 //*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/
 
-#endif
\ No newline at end of file
+#endif
