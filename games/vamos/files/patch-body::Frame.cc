--- body/Frame.cc.orig	Sat Mar 16 01:50:31 2002
+++ body/Frame.cc	Sat Mar 16 01:50:43 2002
@@ -21,6 +21,7 @@
 #include <vamos/body/Frame.h>
 #include <vamos/geometry/Conversions.h>
 
+#include <cassert>
 #include <cmath>
 
 using Vamos_Geometry::Three_Vector;
