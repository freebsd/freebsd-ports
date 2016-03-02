--- dns-terror/getline.c.orig	2002-10-07 02:53:13 UTC
+++ dns-terror/getline.c
@@ -26,6 +26,7 @@ Foundation, Inc., 59 Temple Place - Suit
    is defined.  */
 #define _GNU_SOURCE	1
 #include <stdio.h>
+#include <sys/param.h>
 #include <sys/types.h>
 
 #if defined __GNU_LIBRARY__ && HAVE_GETDELIM
@@ -134,6 +135,7 @@ getstr (lineptr, n, stream, terminator, 
   return ret;
 }
 
+#if __FreeBSD_version < 800067
 int
 getline (lineptr, n, stream)
      char **lineptr;
@@ -152,4 +154,5 @@ getdelim (lineptr, n, delimiter, stream)
 {
   return getstr (lineptr, n, stream, delimiter, 0);
 }
+#endif	/* __FreeBSD_version < 800067 */
 #endif
