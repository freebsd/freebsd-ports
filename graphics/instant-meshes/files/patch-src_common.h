--- src/common.h.orig	2017-09-06 16:18:14 UTC
+++ src/common.h
@@ -30,6 +30,7 @@
 #include <mutex>
 #include <thread>
 #include <algorithm>
+#include <cassert>
 
 #define PARALLELIZE
 #define SINGLE_PRECISION
