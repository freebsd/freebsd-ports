--- base/include/queue.h.orig	2003-09-16 17:34:53 UTC
+++ base/include/queue.h
@@ -24,6 +24,7 @@ ________________________________________
 #ifndef INCLUDED_QUEUE_H_
 #define INCLUDED_QUEUE_H_
 
+#include <assert.h>
 #include "config.h"
 #include "mutex.h"
 
