--- cmn/utils.cpp.orig	Wed Mar 19 10:05:12 2003
+++ cmn/utils.cpp	Sat Oct 25 21:45:15 2003
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
