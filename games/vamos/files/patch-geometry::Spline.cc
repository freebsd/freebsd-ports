--- geometry/Spline.cc.orig	Fri May 30 13:34:43 2003
+++ geometry/Spline.cc	Thu Jul 24 01:31:07 2003
@@ -19,6 +19,7 @@
 
 #include <vamos/geometry/Spline.h>
 
+#include <cassert>
 #include <cmath>
 
 // Construct an empty curve.
