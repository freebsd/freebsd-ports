$FreeBSD$

--- ../../j2se/src/share/native/sun/awt/medialib/mlib_types.h.orig	Sun Mar 20 22:08:20 2005
+++ ../../j2se/src/share/native/sun/awt/medialib/mlib_types.h	Sun Mar 20 22:08:33 2005
@@ -47,7 +47,11 @@
 
 #if defined(_ALLBSD_SOURCE)
 #include <stddef.h>                     /* for ptrdiff_t */
+#if defined(__FreeBSD__) && __FreeBSD__ < 5
+#include <inttypes.h>
+#else
 #include <stdint.h>                     /* for uintptr_t */
+#endif
 #elif defined(__linux__)
 #include <stdint.h>                     /* for uintptr_t */
 #include <malloc.h>                     /* for ptrdiff_t */
