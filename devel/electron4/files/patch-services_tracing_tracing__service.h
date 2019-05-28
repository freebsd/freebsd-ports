--- services/tracing/tracing_service.h.orig	2019-03-15 06:37:32 UTC
+++ services/tracing/tracing_service.h
@@ -18,7 +18,7 @@
 #include "services/tracing/coordinator.h"
 
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_MACOSX) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
 #define PERFETTO_SERVICE_AVAILABLE
 #endif
 
