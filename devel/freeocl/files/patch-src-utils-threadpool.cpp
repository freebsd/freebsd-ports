--- src/utils/threadpool.cpp.orig	2014-07-04 08:45:34.000000000 +0200
+++ src/utils/threadpool.cpp	2014-07-04 08:46:03.000000000 +0200
@@ -18,6 +18,7 @@
 #include "threadpool.h"
 #include <FreeOCL/config.h>
 #include <sched.h>
+#include <xmmintrin.h>
 #include <atomic_ops.h>
 #include <utils/time.h>
 
