Backport of Perfetto's FreeBSD support (upstream 81c39c7f82, Perfetto
v53) to the Perfetto that Dart 3.13 pins (series 1001). Drop it once
Dart pins Perfetto v53 or later.
--- third_party/perfetto/src/src/base/thread_task_runner.cc.orig	2026-09-29 08:00:52 UTC
+++ third_party/perfetto/src/src/base/thread_task_runner.cc
@@ -27,8 +27,9 @@
 #include "perfetto/ext/base/thread_utils.h"
 #include "perfetto/ext/base/unix_task_runner.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !defined(__FreeBSD__)
 #include <sys/prctl.h>
 #endif
 
