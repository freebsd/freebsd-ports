--- ar/src/pass/add_partitioning_variables.cpp.orig	2022-12-05 06:21:57 UTC
+++ ar/src/pass/add_partitioning_variables.cpp
@@ -45,6 +45,7 @@
  *
  ******************************************************************************/
 
+#include <array>
 #include <unordered_set>
 
 #include <ikos/ar/pass/add_partitioning_variables.hpp>
