--- cmn/utils.cpp.orig	Wed Mar 19 10:05:12 2003
+++ cmn/utils.cpp	Fri Oct  6 13:45:47 2006
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
@@ -761,7 +762,7 @@
 
 
 private:
-  Bucket* HashTable::_get(int &index,void* key);
+  Bucket* _get(int &index,void* key);
   /* MODIFIES: index */
   /* EFFECTS: Internal helper function.  Return the Bucket containing key
      or NULL if not found.  Set index to the bucket list for key whether
