--- tools/gn/src/gn/exec_process.cc.orig	2020-05-18 18:48:23 UTC
+++ tools/gn/src/gn/exec_process.cc
@@ -30,6 +30,10 @@
 #include "base/posix/file_descriptor_shuffle.h"
 #endif
 
+#if defined(OS_BSD)
+#include <signal.h>
+#endif
+
 namespace internal {
 
 #if defined(OS_WIN)
