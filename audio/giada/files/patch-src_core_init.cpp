--- src/core/init.cpp.orig	2019-02-22 10:29:43 UTC
+++ src/core/init.cpp
@@ -25,6 +25,7 @@
  * -------------------------------------------------------------------------- */
 
 
+#include <atomic>
 #include <thread>
 #include <ctime>
 #ifdef __APPLE__
