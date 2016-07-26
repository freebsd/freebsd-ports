--- base/include/thread.h.orig	2003-09-16 17:34:53 UTC
+++ base/include/thread.h
@@ -26,7 +26,10 @@ ________________________________________
 
 #include "config.h"
 
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 typedef void (*thread_function)(void * arg);
 
