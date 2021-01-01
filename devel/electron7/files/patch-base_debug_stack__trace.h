--- base/debug/stack_trace.h.orig	2019-12-12 12:38:58 UTC
+++ base/debug/stack_trace.h
@@ -19,6 +19,7 @@
 #if !defined(OS_NACL)
 #include <signal.h>
 #endif
+#include <sys/stdint.h>
 #include <unistd.h>
 #endif
 
