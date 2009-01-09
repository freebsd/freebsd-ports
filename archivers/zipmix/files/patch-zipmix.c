--- zipmix.c.orig	2009-01-08 22:05:10.000000000 -0200
+++ zipmix.c	2009-01-08 22:10:30.000000000 -0200
@@ -4,6 +4,17 @@
 !if 0
 #endif
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if (defined(BSD) && (BSD >= 199306))
+#include <stdlib.h>
+
+#define min(a,b) MIN(a,b)
+#define max(a,b) MAX(a,b)
+#endif
+
 #if defined(_WIN32)
 
 #include <windows.h>
