- workaround for https://github.com/facebook/folly/issues/1637

--- folly/executors/QueueObserver.h.orig	2021-08-26 23:37:53 UTC
+++ folly/executors/QueueObserver.h
@@ -23,6 +23,8 @@
 
 #include <folly/Portability.h>
 
+#include <signal.h>
+
 namespace folly {
 
 class RequestContext;
