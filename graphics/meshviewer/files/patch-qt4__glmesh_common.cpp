--- qt4/glmesh_common.cpp~	2012-05-20 00:04:54.000000000 -0300
+++ qt4/glmesh_common.cpp	2012-05-20 00:05:03.000000000 -0300
@@ -10,6 +10,8 @@
 
 #include "glmesh.h"
 
+#include <GL/glu.h>
+
 void GLMesh::checkForTraps(const char *string, int value)
 {
   GLenum errorCode = glGetError();
