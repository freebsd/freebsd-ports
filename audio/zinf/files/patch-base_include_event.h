--- base/include/event.h.orig	2003-09-16 17:34:53 UTC
+++ base/include/event.h
@@ -24,7 +24,10 @@ ________________________________________
 #ifndef INCLUDED_EVENT_H_
 #define INCLUDED_EVENT_H_
 
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include "config.h"
 #include "errors.h"
 
