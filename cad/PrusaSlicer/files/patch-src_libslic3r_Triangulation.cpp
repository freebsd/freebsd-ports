--- src/libslic3r/Triangulation.cpp.orig	2024-12-20 11:54:34 UTC
+++ src/libslic3r/Triangulation.cpp
@@ -2,6 +2,9 @@
 ///|/
 ///|/ PrusaSlicer is released under the terms of the AGPLv3 or higher
 ///|/
+
+#include <boost/next_prior.hpp>
+
 #include "Triangulation.hpp"
 
 #include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
