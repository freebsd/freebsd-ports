$FreeBSD$

--- ../../j2se/src/solaris/native/sun/java2d/j2d_md.h.orig	Sun Mar 20 22:20:43 2005
+++ ../../j2se/src/solaris/native/sun/java2d/j2d_md.h	Sun Mar 20 22:24:40 2005
@@ -14,7 +14,11 @@
  * NetBSD's doesn't either, so let's do it for everyone.
  */
 #if defined(__linux__) || defined(_ALLBSD_SOURCE)
+#if defined(__FreeBSD__) && __FreeBSD__ < 5
+#include <inttypes.h>
+#else
 #include <stdint.h>
+#endif
 #endif /* __linux__ || _ALLBSD_SOURCE */
 
 typedef unsigned char	jubyte;
