--- src/VTKViewer/VTKViewer_ConvexTool.cxx.orig	2009-06-01 15:14:39.000000000 +0700
+++ src/VTKViewer/VTKViewer_ConvexTool.cxx	2009-06-01 15:18:32.000000000 +0700
@@ -27,6 +27,7 @@
 #ifdef WNT
 #include <algorithm>
 #endif
+#include <algorithm>
 
 #include <vtkUnstructuredGrid.h>
 #include <vtkGeometryFilter.h>
