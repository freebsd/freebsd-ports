--- cmn/xetp.cpp.orig	Wed Jan 19 12:54:30 2000
+++ cmn/xetp.cpp	Sat Oct 25 21:46:02 2003
@@ -29,9 +29,10 @@
 
 #include "stdafx.h"
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #if X11
-#include <strstream.h>
+#include <strstream>
 #endif
 #if WIN32
 #include <strstrea.h>
