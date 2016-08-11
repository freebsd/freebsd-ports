--- sidplay.cpp.orig	2002-09-28 18:44:02 UTC
+++ sidplay.cpp
@@ -18,8 +18,8 @@
 //
 
 #include <ctype.h>
-#include <iomanip.h>
-#include <fstream.h>
+#include <iomanip>
+#include <iostream>
 #include <signal.h>
 #include <stdlib.h>
 #include <string.h>
@@ -41,6 +41,14 @@
 #define DISALLOW_STEREO_SOUND
 #endif
 
+using std::cerr;
+using std::cout;
+using std::dec;
+using std::endl;
+using std::hex;
+using std::setfill;
+using std::setw;
+
 // Error and status message numbers.
 enum
 {
