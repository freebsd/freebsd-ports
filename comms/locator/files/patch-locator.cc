--- locator.cc.orig	2001-07-29 07:33:02.000000000 -0400
+++ locator.cc	2011-07-01 08:26:29.000000000 -0400
@@ -3,15 +3,19 @@
 /* Last change 29.07.2001  */
 
 /* A few includes */
-#include <iostream.h>
-#include <string.h>
-#include <stdio.h>
+#include <iostream>
+#include <cstdio>
+#include <cstring>
+
+using std::iostream;
+using std::ostream;
+using std::cout;
 
 /* A few definitions */
 #define VERSION "0.1"
 
 /* Main program */
-main(int argc, char *argv[]) {
+int main(int argc, char *argv[]) {
   float c_long, c_lat;
   char  *locator;
 
