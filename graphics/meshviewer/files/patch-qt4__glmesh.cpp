--- qt4/glmesh.cpp.orig	2008-09-09 21:38:45 UTC
+++ qt4/glmesh.cpp
@@ -21,6 +21,8 @@
 #include "mview.h"
 #include "coordinates.h"
 
+#include <GL/glu.h>
+
 // for FPS
 unsigned long timeCounter;
 unsigned int frameCounter;
