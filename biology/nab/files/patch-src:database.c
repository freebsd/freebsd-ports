--- src/database.c.orig	Thu Nov 16 15:37:11 2000
+++ src/database.c	Fri Feb 14 12:15:53 2003
@@ -64,6 +64,13 @@
  *              The TOTAL database name MUST NEVER be longer than
  *              can be contained in the String object.
  */
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if defined(BSD)
+#include <math.h>
+#endif
 
 
 
