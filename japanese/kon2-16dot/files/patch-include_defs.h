--- include/defs.h.orig	1997-01-24 16:04:32.000000000 +0900
+++ include/defs.h	2012-05-10 00:14:28.733561206 +0900
@@ -37,4 +37,6 @@
 #define	FAILURE	(-1)
 #define SUCCESS	(0)
 
+#define SafeFree(x)   do { if ((x) != NULL) free(x), (x) = NULL; } while (0)
+
 #endif
