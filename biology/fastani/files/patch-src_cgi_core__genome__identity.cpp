--- src/cgi/core_genome_identity.cpp.orig	2024-09-20 22:30:43 UTC
+++ src/cgi/core_genome_identity.cpp
@@ -10,6 +10,8 @@
 #include <functional>
 #include <omp.h>
 
+#include <unistd.h>
+
 //Own includes
 #include "map/include/map_parameters.hpp"
 #include "map/include/base_types.hpp"
