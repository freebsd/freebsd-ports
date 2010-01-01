--- libiqxmlrpc/executor.h.orig	2010-01-01 15:27:17.000000000 +0600
+++ libiqxmlrpc/executor.h	2010-01-01 15:27:25.000000000 +0600
@@ -26,7 +26,7 @@
 #pragma warning(disable: 4275)
 #endif
 
-#include <boost/thread.hpp>
+#include <boost/thread/thread.hpp>
 #include <boost/thread/mutex.hpp>
 #include <boost/thread/condition.hpp>
 
