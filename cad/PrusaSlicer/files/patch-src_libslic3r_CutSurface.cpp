--- src/libslic3r/CutSurface.cpp.orig	2024-03-01 11:43:14 UTC
+++ src/libslic3r/CutSurface.cpp
@@ -29,6 +29,7 @@ using namespace Slic3r;
 using namespace Slic3r;
 #include "ExPolygonsIndex.hpp"
 
+#include <boost/next_prior.hpp>
 #include <CGAL/Polygon_mesh_processing/corefinement.h>
 #include <CGAL/Exact_integer.h>
 #include <CGAL/Surface_mesh.h>
