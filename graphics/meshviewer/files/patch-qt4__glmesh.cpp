--- qt4/glmesh.cpp~	2012-05-20 00:04:04.000000000 -0300
+++ qt4/glmesh.cpp	2012-05-20 00:04:21.000000000 -0300
@@ -21,6 +21,8 @@
 #include "mview.h"
 #include "coordinates.h"
 
+#include <GL/glu.h>
+
 // for FPS
 unsigned long timeCounter;
 unsigned int frameCounter;
