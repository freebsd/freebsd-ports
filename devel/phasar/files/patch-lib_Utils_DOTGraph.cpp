- https://github.com/secure-software-engineering/phasar/issues/762

--- lib/Utils/DOTGraph.cpp.orig	2025-03-16 05:23:34 UTC
+++ lib/Utils/DOTGraph.cpp
@@ -23,6 +23,7 @@
 #include <fstream>
 #include <iterator>
 #include <ostream>
+#include <sstream>
 #include <utility>
 
 namespace psr {
