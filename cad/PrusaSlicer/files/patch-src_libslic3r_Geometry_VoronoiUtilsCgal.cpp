--- src/libslic3r/Geometry/VoronoiUtilsCgal.cpp.orig	2024-09-18 13:39:04 UTC
+++ src/libslic3r/Geometry/VoronoiUtilsCgal.cpp
@@ -2,6 +2,7 @@
 ///|/
 ///|/ PrusaSlicer is released under the terms of the AGPLv3 or higher
 ///|/
+#include <boost/next_prior.hpp>
 #include <CGAL/Exact_predicates_exact_constructions_kernel.h>
 #include <CGAL/Arr_segment_traits_2.h>
 #include <CGAL/Surface_sweep_2_algorithms.h>
@@ -333,4 +334,4 @@ VoronoiUtilsCgal::is_voronoi_diagram_planar_angle(cons
     return true;
 }
 
-} // namespace Slic3r::Geometry
\ No newline at end of file
+} // namespace Slic3r::Geometry
