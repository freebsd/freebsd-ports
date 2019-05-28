--- content/public/test/browser_test_base.cc.orig	2019-03-15 06:37:23 UTC
+++ content/public/test/browser_test_base.cc
@@ -52,6 +52,10 @@
 #include "ui/gl/gl_implementation.h"
 #include "ui/gl/gl_switches.h"
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#endif
+
 #if defined(OS_POSIX)
 #include "base/process/process_handle.h"
 #endif
