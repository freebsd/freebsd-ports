--- v8/src/diagnostics/perf-jit.h.orig	2025-05-10 23:04:03 UTC
+++ v8/src/diagnostics/perf-jit.h
@@ -31,7 +31,7 @@
 #include "include/v8config.h"
 
 // {PerfJitLogger} is only implemented on Linux & Darwin.
-#if V8_OS_LINUX || V8_OS_DARWIN
+#if defined(V8_OS_LINUX) || defined(V8_OS_DARWIN) || defined(V8_OS_BSD)
 
 #include "src/logging/log.h"
 
