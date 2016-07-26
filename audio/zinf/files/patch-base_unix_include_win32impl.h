--- base/unix/include/win32impl.h.orig	2003-09-16 17:34:54 UTC
+++ base/unix/include/win32impl.h
@@ -24,7 +24,10 @@ ________________________________________
 #ifndef INCLUDED_WIN32IMPL_H_
 #define INCLUDED_WIN32IMPL_H_
 
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include <limits.h>
 
 #include "config.h"
