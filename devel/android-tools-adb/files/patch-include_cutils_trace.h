--- include/cutils/trace.h.orig	2017-06-20 10:50:27 UTC
+++ include/cutils/trace.h
@@ -18,8 +18,14 @@
 #define _LIBS_CUTILS_TRACE_H
 
 #include <inttypes.h>
+#ifdef __cplusplus
+#include <atomic>
+using std::atomic_bool;
+using std::memory_order_acquire;
+#else
 #include <stdatomic.h>
 #include <stdbool.h>
+#endif
 #include <stdint.h>
 #include <stdio.h>
 #include <sys/cdefs.h>
