--- base/unix/include/win32impl.h.orig	Thu Feb  6 02:52:42 2003
+++ base/unix/include/win32impl.h	Mon Aug 18 17:36:37 2003
@@ -24,7 +24,10 @@
 #ifndef INCLUDED_WIN32IMPL_H_
 #define INCLUDED_WIN32IMPL_H_
 
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include <limits.h>
 
 #include "config.h"
