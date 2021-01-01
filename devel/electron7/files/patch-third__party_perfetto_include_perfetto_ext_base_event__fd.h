--- third_party/perfetto/include/perfetto/ext/base/event_fd.h.orig	2019-12-12 12:45:20 UTC
+++ third_party/perfetto/include/perfetto/ext/base/event_fd.h
@@ -20,8 +20,8 @@
 #include "perfetto/base/build_config.h"
 #include "perfetto/ext/base/scoped_file.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) && (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID))
 #define PERFETTO_USE_EVENTFD() 1
 #else
 #define PERFETTO_USE_EVENTFD() 0
