--- qt4/glmesh_common.cpp.orig	2010-10-15 15:35:52 UTC
+++ qt4/glmesh_common.cpp
@@ -10,6 +10,8 @@
 
 #include "glmesh.h"
 
+#include <GL/glu.h>
+
 void GLMesh::checkForTraps(const char *string, int value)
 {
   GLenum errorCode = glGetError();
