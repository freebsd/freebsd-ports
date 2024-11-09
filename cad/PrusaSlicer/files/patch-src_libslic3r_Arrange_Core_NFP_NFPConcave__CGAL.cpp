--- src/libslic3r/Arrange/Core/NFP/NFPConcave_CGAL.cpp.orig	2024-09-18 13:39:04 UTC
+++ src/libslic3r/Arrange/Core/NFP/NFPConcave_CGAL.cpp
@@ -2,6 +2,9 @@
 ///|/
 ///|/ PrusaSlicer is released under the terms of the AGPLv3 or higher
 ///|/
+
+#include <boost/next_prior.hpp>
+
 #include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
 #include <CGAL/partition_2.h>
 #include <CGAL/Partition_traits_2.h>
