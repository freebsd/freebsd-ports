--- src/vasprintf.c.orig	Sat May 21 19:01:50 2005
+++ src/vasprintf.c	Mon Jul 11 23:23:19 2005
@@ -78,6 +78,10 @@
 #include <ctype.h>
 #include <limits.h>
 
+#ifndef va_copy
+#define va_copy(to,fr) ((to)=(fr))
+#endif
+
 #define ALLOC_CHUNK 2048
 #define ALLOC_SECURITY_MARGIN 1024   /* big value because some platforms have very big 'G' exponent */
 #if ALLOC_CHUNK < ALLOC_SECURITY_MARGIN
