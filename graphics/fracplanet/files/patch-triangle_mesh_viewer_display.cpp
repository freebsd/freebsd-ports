--- triangle_mesh_viewer_display.cpp~	2012-05-19 23:49:24.000000000 -0300
+++ triangle_mesh_viewer_display.cpp	2012-05-19 23:49:55.000000000 -0300
@@ -24,6 +24,8 @@
 #include "matrix33.h"
 #include "triangle_mesh_viewer.h"
 
+#include <GL/glu.h>
+
 TriangleMeshViewerDisplay::TriangleMeshViewerDisplay(TriangleMeshViewer* parent,const QGLFormat& format,const ParametersRender* param,const std::vector<const TriangleMesh*>& m,bool verbose)
   :QGLWidget(format,parent)
   ,_notify(*parent)
