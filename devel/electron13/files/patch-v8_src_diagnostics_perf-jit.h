--- v8/src/diagnostics/perf-jit.h.orig	2021-07-15 19:15:58 UTC
+++ v8/src/diagnostics/perf-jit.h
@@ -31,7 +31,7 @@
 #include "include/v8config.h"
 
 // {PerfJitLogger} is only implemented on Linux.
-#if V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
 
 #include "src/logging/log.h"
 
