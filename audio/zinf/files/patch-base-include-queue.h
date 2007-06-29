--- base/include/queue.h.orig	Wed Sep 17 00:34:53 2003
+++ base/include/queue.h	Fri Jun 29 17:36:37 2007
@@ -24,6 +24,7 @@
 #ifndef INCLUDED_QUEUE_H_
 #define INCLUDED_QUEUE_H_
 
+#include <assert.h>
 #include "config.h"
 #include "mutex.h"
 
