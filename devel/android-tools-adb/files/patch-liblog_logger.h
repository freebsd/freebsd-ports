--- liblog/logger.h.orig	2020-02-11 20:44:45 UTC
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
 #include <sys/cdefs.h>
 
 #include <log/log.h>
