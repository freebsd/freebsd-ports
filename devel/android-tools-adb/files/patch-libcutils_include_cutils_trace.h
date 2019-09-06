--- libcutils/include/cutils/trace.h.orig	2019-07-17 19:54:09 UTC
+++ libcutils/include/cutils/trace.h
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
