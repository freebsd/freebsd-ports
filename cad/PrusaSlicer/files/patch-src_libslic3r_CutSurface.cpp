--- src/libslic3r/CutSurface.cpp.orig	2024-12-20 11:54:34 UTC
+++ src/libslic3r/CutSurface.cpp
@@ -27,6 +27,8 @@ using namespace Slic3r;
 //#define DEBUG_OUTPUT_DIR std::string("C:/data/temp/cutSurface/")
 
 using namespace Slic3r;
+#include <boost/next_prior.hpp>
+
 #include <CGAL/Polygon_mesh_processing/corefinement.h>
 #include <CGAL/Exact_integer.h>
 #include <CGAL/Surface_mesh.h>
