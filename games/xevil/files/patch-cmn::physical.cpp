--- cmn/physical.cpp.orig	Wed Jan 19 20:38:14 2000
+++ cmn/physical.cpp	Sat Oct 25 21:43:15 2003
@@ -33,10 +33,11 @@
 // Include Files
 #include "xdata.h"
 #include "physical.h"
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 
 #if X11
-#include <strstream.h>
+#include <strstream>
 #endif
 #if WIN32
 #include <strstrea.h>
