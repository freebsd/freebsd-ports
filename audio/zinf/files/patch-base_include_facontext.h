--- base/include/facontext.h.orig	2003-09-16 17:58:13 UTC
+++ base/include/facontext.h
@@ -25,7 +25,10 @@ ________________________________________
 #ifndef INCLUDED_FACONTEXT_H_
 #define INCLUDED_FACONTEXT_H_
 
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 #include "config.h"
 #include "preferences.h"
