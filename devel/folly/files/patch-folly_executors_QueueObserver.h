- workaround for https://github.com/facebook/folly/issues/1637

--- folly/executors/QueueObserver.h.orig	2022-11-25 05:13:23 UTC
+++ folly/executors/QueueObserver.h
@@ -26,6 +26,8 @@
 #include <folly/Synchronized.h>
 #include <folly/portability/SysTypes.h>
 
+#include <signal.h>
+
 namespace folly {
 
 class RequestContext;
