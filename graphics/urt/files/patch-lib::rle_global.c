--- lib/rle_global.c.orig	Wed Jan 29 03:23:03 1992
+++ lib/rle_global.c	Fri Dec 27 23:20:42 2002
@@ -76,8 +76,10 @@
     8,				/* cmaplen (log2 of length of color map) */
     NULL,			/* pointer to color map */
     NULL,			/* pointer to comment strings */
+#if 0
     stdout,			/* output file */
     { 7 },			/* RGB channels only */
+#endif
     0L,				/* Can't free name and file fields. */
     "Urt",			/* Default "program name". */
     "no file",			/* No file name given. */
