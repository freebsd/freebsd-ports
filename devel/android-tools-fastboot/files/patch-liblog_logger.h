--- liblog/logger.h.orig	2019-08-13 02:10:58 UTC
+++ liblog/logger.h
@@ -16,7 +16,13 @@
 
 #pragma once
 
+#ifdef __cplusplus
+#include <atomic>
+using std::atomic_int;
+using std::atomic_uintptr_t;
+#else
 #include <stdatomic.h>
+#endif
 
 #include <cutils/list.h>
 #include <log/log.h>
