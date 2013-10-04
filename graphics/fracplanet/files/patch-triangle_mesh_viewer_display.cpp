--- triangle_mesh_viewer_display.cpp.orig	2009-10-05 00:26:36.000000000 +0200
+++ triangle_mesh_viewer_display.cpp	2013-10-03 00:25:53.000000000 +0200
@@ -24,6 +24,8 @@
 #include "matrix33.h"
 #include "triangle_mesh_viewer.h"
 
+#include <GL/glu.h>
+
 TriangleMeshViewerDisplay::TriangleMeshViewerDisplay(TriangleMeshViewer* parent,const QGLFormat& format,const ParametersRender* param,const std::vector<const TriangleMesh*>& m,bool verbose)
   :QGLWidget(format,parent)
   ,_notify(*parent)
