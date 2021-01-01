--- content/public/test/browser_test_base.cc.orig	2019-09-10 11:14:02 UTC
+++ content/public/test/browser_test_base.cc
@@ -75,6 +75,10 @@
 #include "ui/views/test/event_generator_delegate_mac.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#endif
+
 #if defined(OS_POSIX)
 #include "base/process/process_handle.h"
 #endif
