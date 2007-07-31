--- cmn/utils.cpp.orig	2003-03-19 10:05:12.000000000 +0100
+++ cmn/utils.cpp	2007-07-31 15:43:42.000000000 +0200
@@ -30,16 +30,17 @@
 
 // Include Files
 #include "stdafx.h"
-#include <iostream.h>
-#include <limits.h>
-#include <string.h>
-#include <ctype.h>
-#include <fstream.h>
+#include <iostream>
+#include <climits>
+#include <cstring>
+#include <cctype>
+#include <fstream>
+using namespace std;
 #if WIN32
 #include <strstrea.h>
 #endif
 #if X11
-#include <strstream.h>
+#include <strstream>
 #endif
 
 #ifdef WIN32
@@ -605,7 +606,7 @@
   // Not tested.
   out->write_int(len);
   for (int n = 0; n < len; n++) {
-    out->write_int((int)data[n]);
+    out->write_int((intptr_t)data[n]);
   }
 }
 
@@ -761,7 +762,7 @@
 
 
 private:
-  Bucket* HashTable::_get(int &index,void* key);
+  Bucket* _get(int &index,void* key);
   /* MODIFIES: index */
   /* EFFECTS: Internal helper function.  Return the Bucket containing key
      or NULL if not found.  Set index to the bucket list for key whether
@@ -944,7 +945,7 @@
 // Pretty crappy hash function, I know.
 // Careful if bucketsNum is a power of 2.
 int HashTable::defaultHash(void* key,int bucketsNum) {
-  return ((unsigned int)key) % bucketsNum;
+  return ((unsigned intptr_t)key) % bucketsNum;
 }
 
 
