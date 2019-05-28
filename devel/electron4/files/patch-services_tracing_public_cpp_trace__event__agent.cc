--- services/tracing/public/cpp/trace_event_agent.cc.orig	2019-03-15 06:37:32 UTC
+++ services/tracing/public/cpp/trace_event_agent.cc
@@ -23,7 +23,7 @@
 #include "services/tracing/public/mojom/constants.mojom.h"
 
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_MACOSX) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
 #define PERFETTO_AVAILABLE
 #include "services/tracing/public/cpp/perfetto/producer_client.h"
 #endif
