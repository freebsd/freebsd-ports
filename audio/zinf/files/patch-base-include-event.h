--- base/include/event.h.orig	Wed Sep 17 02:34:53 2003
+++ base/include/event.h	Mon Feb 16 12:15:13 2004
@@ -24,7 +24,10 @@
 #ifndef INCLUDED_EVENT_H_
 #define INCLUDED_EVENT_H_
 
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include "config.h"
 #include "errors.h"
 
