--- cgx_1.1/src/cgxToCdsm.cpp.orig	Thu Aug  7 15:39:06 2003
+++ cgx_1.1/src/cgxToCdsm.cpp	Thu Aug  7 15:42:01 2003
@@ -28,7 +28,7 @@
 #include "knotVect.h"
 #include "nurbsBase.h"
 #include "ptrList.h"
-#include "iostream.h"
+#include "iostream"
 
 sLocn*  amb = 0;  // Ambiguous points.
 int     ambSize;
