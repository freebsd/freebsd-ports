--- triangle_mesh_viewer_display.cpp.orig	2009-10-04 22:26:36 UTC
+++ triangle_mesh_viewer_display.cpp
@@ -24,6 +24,8 @@
 #include "matrix33.h"
 #include "triangle_mesh_viewer.h"
 
+#include <GL/glu.h>
+
 TriangleMeshViewerDisplay::TriangleMeshViewerDisplay(TriangleMeshViewer* parent,const QGLFormat& format,const ParametersRender* param,const std::vector<const TriangleMesh*>& m,bool verbose)
   :QGLWidget(format,parent)
   ,_notify(*parent)
