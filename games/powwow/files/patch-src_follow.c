--- src/follow.c.orig	2020-07-10 21:06:39 UTC
+++ src/follow.c
@@ -8,6 +8,10 @@
  *
  */
 
+#ifdef BSD_LIKE
+#define COMPAT_43TTY
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
