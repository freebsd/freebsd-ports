--- cmn/physical.cpp.orig	2000-01-19 20:38:14.000000000 +0100
+++ cmn/physical.cpp	2007-07-31 15:54:01.000000000 +0200
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
@@ -1844,7 +1845,7 @@
   }
 
   // Use the pixmap resource id as the base.
-  u_int cmnBitsId = (unsigned int)mc->pixmapBits[baseDir][animNum];
+  u_int cmnBitsId = (unsigned intptr_t)mc->pixmapBits[baseDir][animNum];
 
   // It is ok to call OneTransform::compute_key() even if there is no 
   // transformation, will just return 0x0.  
