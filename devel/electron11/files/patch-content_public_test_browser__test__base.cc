--- content/public/test/browser_test_base.cc.orig	2021-01-07 00:36:33 UTC
+++ content/public/test/browser_test_base.cc
@@ -105,6 +105,10 @@
 #include "ui/views/test/event_generator_delegate_mac.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#endif
+
 #if defined(OS_POSIX)
 #include "base/process/process_handle.h"
 #endif
