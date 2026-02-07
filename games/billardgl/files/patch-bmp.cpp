--- bmp.cpp.orig	2002-04-22 10:31:24 UTC
+++ bmp.cpp
@@ -4,14 +4,16 @@
 // Modified by Volker Blanz, 25.4.2001
 //
 
-#include <iostream.h>
-#include <fstream.h>
+#include <iostream>
+#include <fstream>
 #include <stdio.h>
 #include <string.h>
 #include "LA.h"
 #include "Namen.h"
 #include "bmp.h"
 
+using namespace std;
+
 // from ioutil:
 
 WORDX readWord(FILE *f) {
