--- cmn/role.cpp.orig	Wed Jan 19 12:54:34 2000
+++ cmn/role.cpp	Sat Oct 25 21:43:43 2003
@@ -29,9 +29,10 @@
 
 #include "stdafx.h"
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #if X11
-#include <strstream.h>
+#include <strstream>
 #include <time.h>
 #endif
 #if WIN32
