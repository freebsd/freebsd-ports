--- tleap/database.c.orig	Sat Nov  9 18:36:58 2002
+++ tleap/database.c	Wed Jan 29 09:56:46 2003
@@ -185,6 +185,13 @@
 }
 
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if defined(BSD)
+#include <math.h>
+#endif
 
 
 
