--- texk/dvipdfm/thumbnail.c.orig	2002-12-25 18:51:16.000000000 +0100
+++ texk/dvipdfm/thumbnail.c	2010-03-30 04:44:51.000000000 +0200
@@ -79,7 +79,7 @@
   }
   if (fread (sigbytes, 1, sizeof(sigbytes), thumb_file) !=
       sizeof(sigbytes) ||
-      (!png_check_sig (sigbytes, sizeof(sigbytes)))) {
+      (png_sig_cmp (sigbytes, 0, sizeof(sigbytes)))) {
     fprintf (stderr, "\nThumbnail not a png file! Skipping\n");
     return NULL;
   }
