--- body/Suspension.cc.orig	Fri Jan 24 08:44:47 2003
+++ body/Suspension.cc	Thu Jul 24 01:32:35 2003
@@ -20,6 +20,8 @@
 
 #include <vamos/geometry/Conversions.h>
 #include <vamos/body/Suspension.h>
+
+#include <cassert>
 #include <cmath>
 
 using Vamos_Geometry::Three_Vector;
