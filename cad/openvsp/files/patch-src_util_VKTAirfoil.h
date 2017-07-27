--- src/util/VKTAirfoil.h.orig	2017-07-22 12:50:11 UTC
+++ src/util/VKTAirfoil.h
@@ -11,7 +11,7 @@
 #if !defined(VKTAIRFOIL__INCLUDED_)
 #define VKTAIRFOIL__INCLUDED_
 
-#include "vec3d.h"
+#include "Vec3d.h"
 
 vec3d vkt_airfoil_point( double theta, double epsilon, double kappa, double tau );
 
