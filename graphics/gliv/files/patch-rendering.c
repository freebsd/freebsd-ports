--- rendering.c.orig	Thu Sep 13 12:55:36 2001
+++ rendering.c	Sun Sep 30 20:47:40 2001
@@ -27,9 +27,14 @@
 #include <GL/glu.h>
 #include "gliv.h"
 
+/* FreeBSD has no fminf/fmin, so fake it */
+#if 0
 #ifndef HAVE_FMINF
 #define fminf fmin
 #endif
+#endif
+
+#define fminf(A, B) ((A) < (B) ? (A) : (B))
 
 #ifndef HAVE_FABSF
 #define fabsf fabs
