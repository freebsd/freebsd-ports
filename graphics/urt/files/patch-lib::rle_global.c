--- lib/rle_global.c.orig	Tue Jan 28 18:23:03 1992
+++ lib/rle_global.c	Sun Jan 30 15:19:36 2005
@@ -76,7 +76,7 @@
     8,				/* cmaplen (log2 of length of color map) */
     NULL,			/* pointer to color map */
     NULL,			/* pointer to comment strings */
-    stdout,			/* output file */
+    0,				/* stdout, output file */
     { 7 },			/* RGB channels only */
     0L,				/* Can't free name and file fields. */
     "Urt",			/* Default "program name". */
