--- shared.c.orig	2021-02-18 15:46:01 UTC
+++ shared.c
@@ -14,6 +14,9 @@
 #include <X11/Xutil.h>
 #include <errno.h>
 #include <string.h>
+
+#define GOLDDIG_EXTERN
+
 #include <golddig.h>
 /* Include all the bitmaps for the terrain blocks */
 #include <bitmaps.h>
