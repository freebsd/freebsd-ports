--- base/include/thread.h.orig	Thu Feb  6 02:52:49 2003
+++ base/include/thread.h	Mon Aug 18 17:33:09 2003
@@ -26,7 +26,10 @@
 
 #include "config.h"
 
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 typedef void (*thread_function)(void * arg);
 
