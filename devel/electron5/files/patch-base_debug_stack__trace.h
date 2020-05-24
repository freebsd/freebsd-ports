--- base/debug/stack_trace.h.orig	2019-04-08 08:32:37 UTC
+++ base/debug/stack_trace.h
@@ -16,6 +16,7 @@
 #include "build/build_config.h"
 
 #if defined(OS_POSIX)
+#include <sys/stdint.h>
 #include <unistd.h>
 #endif
 
