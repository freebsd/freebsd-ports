--- base/include/facontext.h.orig	Thu Feb  6 02:52:52 2003
+++ base/include/facontext.h	Mon Aug 18 17:34:13 2003
@@ -25,7 +25,10 @@
 #ifndef INCLUDED_FACONTEXT_H_
 #define INCLUDED_FACONTEXT_H_
 
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 #include "config.h"
 #include "preferences.h"
