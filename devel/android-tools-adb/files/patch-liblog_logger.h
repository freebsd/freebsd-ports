--- liblog/logger.h.orig	2019-07-17 19:54:09 UTC
+++ liblog/logger.h
@@ -16,8 +16,14 @@
 
 #pragma once
 
+#ifdef __cplusplus
+#include <atomic>
+using std::atomic_int;
+using std::atomic_uintptr_t;
+#else
 #include <stdatomic.h>
 #include <stdbool.h>
+#endif
 
 #include <cutils/list.h>
 #include <log/log.h>
