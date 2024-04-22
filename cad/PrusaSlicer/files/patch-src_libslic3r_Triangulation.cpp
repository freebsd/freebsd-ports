--- src/libslic3r/Triangulation.cpp.orig	2024-03-01 11:48:14 UTC
+++ src/libslic3r/Triangulation.cpp
@@ -2,6 +2,9 @@
 ///|/
 ///|/ PrusaSlicer is released under the terms of the AGPLv3 or higher
 ///|/
+
+#include <boost/next_prior.hpp>
+
 #include "Triangulation.hpp"
 #include "IntersectionPoints.hpp"
 #include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
