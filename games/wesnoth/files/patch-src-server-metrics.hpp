--- src/server/metrics.hpp.orig	2013-11-09 20:10:45.000000000 +0400
+++ src/server/metrics.hpp	2013-11-09 20:10:50.000000000 +0400
@@ -27,6 +27,7 @@
 #endif
 
 #include "simple_wml.hpp"
+#include <time.h>
 
 class metrics
 {
