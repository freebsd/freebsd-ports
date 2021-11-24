--- v8/src/diagnostics/perf-jit.cc.orig	2021-07-15 19:15:58 UTC
+++ v8/src/diagnostics/perf-jit.cc
@@ -30,7 +30,7 @@
 #include "src/common/assert-scope.h"
 
 // Only compile the {PerfJitLogger} on Linux.
-#if V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
 
 #include <fcntl.h>
 #include <sys/mman.h>
