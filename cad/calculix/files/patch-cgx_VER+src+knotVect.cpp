--- cgx_1.1/src/knotVect.cpp.orig	Thu Aug  7 15:40:23 2003
+++ cgx_1.1/src/knotVect.cpp	Thu Aug  7 15:47:46 2003
@@ -19,7 +19,7 @@
  */
 
 #include "knotVect.h"
-#include <iostream.h>
+#include <iostream>
 
 knotVector::knotVector ( knot* knotArrayToCopy, unsigned size, unsigned knotVectType )
 {
