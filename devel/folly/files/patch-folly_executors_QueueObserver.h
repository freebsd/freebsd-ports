- workaround for https://github.com/facebook/folly/issues/1637

--- folly/executors/QueueObserver.h.orig	2025-11-02 05:43:14 UTC
+++ folly/executors/QueueObserver.h
@@ -29,6 +29,8 @@
 #include <folly/Synchronized.h>
 #include <folly/portability/SysTypes.h>
 
+#include <signal.h>
+
 namespace folly {
 
 class RequestContext;
