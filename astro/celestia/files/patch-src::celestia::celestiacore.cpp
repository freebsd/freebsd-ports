--- src/celestia/celestiacore.cpp.orig	Sat Aug 30 20:44:13 2003
+++ src/celestia/celestiacore.cpp	Sat Aug 30 20:48:22 2003
@@ -38,7 +38,6 @@
 #include "celestiacore.h"
 #include <celutil/debug.h>
 
-
 using namespace std;
 
 static const int DragThreshold = 3;
@@ -1138,8 +1137,8 @@
             {
                 double distFromSun = body.getHeliocentricPosition(t).distanceFromOrigin();
                 float planetTemp = sun->getTemperature() * 
-                    (float) (pow(1 - body.getAlbedo(), 0.25) *
-                             sqrt(sun->getRadius() / (2 * distFromSun)));
+                   (float) (pow((double)(1 - body.getAlbedo()),(double)( 0.25) *
+                             sqrt(sun->getRadius() / (2 * distFromSun))));
                 overlay << setprecision(0);
                 overlay << "Temperature: " << planetTemp << " K\n";
                 overlay << setprecision(3);
