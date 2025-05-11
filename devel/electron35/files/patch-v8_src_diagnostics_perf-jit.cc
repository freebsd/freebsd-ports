--- v8/src/diagnostics/perf-jit.cc.orig	2025-05-10 23:04:03 UTC
+++ v8/src/diagnostics/perf-jit.cc
@@ -31,7 +31,7 @@
 #include "src/flags/flags.h"
 
 // Only compile the {PerfJitLogger} on Linux & Darwin.
-#if V8_OS_LINUX || V8_OS_DARWIN
+#if defined(V8_OS_LINUX) || defined(V8_OS_DARWIN) || defined(V8_OS_BSD)
 
 #include <fcntl.h>
 #include <sys/mman.h>
