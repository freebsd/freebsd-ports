--- hexfile.h.orig	Tue Nov 19 12:49:44 2002
+++ hexfile.h	Tue Nov 19 12:50:20 2002
@@ -43,10 +43,11 @@
 #ifndef H_HEXFILE
 #define H_HEXFILE
 
-#include <fstream.h>
+#include <fstream>
 
 #include "picport.h"
 
+using namespace std;
 class hexfile {
   static const int size = 0x4000;
   short pgm [size];
