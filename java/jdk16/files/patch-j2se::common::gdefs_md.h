$FreeBSD$

--- ../../j2se/src/solaris/native/common/gdefs_md.h.orig	Sun Mar 20 22:14:34 2005
+++ ../../j2se/src/solaris/native/common/gdefs_md.h	Sun Mar 20 22:15:13 2005
@@ -19,5 +19,9 @@
 #include <malloc.h>
 #endif /* __linux__ */
 #ifdef _ALLBSD_SOURCE
+#if defined(__FreeBSD__) && __FreeBSD__ < 5
+#include <inttypes.h>
+#else
 #include <stdint.h>
+#endif
 #endif /* _ALLBSD_SOURCE */
