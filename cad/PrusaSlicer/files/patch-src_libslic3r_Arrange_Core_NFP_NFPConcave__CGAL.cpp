--- src/libslic3r/Arrange/Core/NFP/NFPConcave_CGAL.cpp.orig	2024-03-01 12:13:10 UTC
+++ src/libslic3r/Arrange/Core/NFP/NFPConcave_CGAL.cpp
@@ -5,6 +5,8 @@
 #include "NFP.hpp"
 #include "NFPConcave_CGAL.hpp"
 
+#include <boost/next_prior.hpp>
+
 #include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
 #include <CGAL/partition_2.h>
 #include <CGAL/Partition_traits_2.h>
