--- dns-terror/getline.c.orig	2009-03-25 02:34:45.000000000 -0400
+++ dns-terror/getline.c	2009-03-25 02:38:48.000000000 -0400
@@ -26,6 +26,7 @@
    is defined.  */
 #define _GNU_SOURCE	1
 #include <stdio.h>
+#include <sys/param.h>
 #include <sys/types.h>
 
 #if defined __GNU_LIBRARY__ && HAVE_GETDELIM
@@ -134,6 +135,7 @@
   return ret;
 }
 
+#if __FreeBSD_version < 800067
 int
 getline (lineptr, n, stream)
      char **lineptr;
@@ -152,4 +154,5 @@
 {
   return getstr (lineptr, n, stream, delimiter, 0);
 }
+#endif	/* __FreeBSD_version < 800067 */
 #endif
