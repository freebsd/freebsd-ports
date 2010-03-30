--- texk/dvipdfm/pngimage.c.orig	2002-12-25 18:51:16.000000000 +0100
+++ texk/dvipdfm/pngimage.c	2010-03-30 04:45:06.000000000 +0200
@@ -42,7 +42,7 @@
   rewind (png_file);
   if (fread (sigbytes, 1, sizeof(sigbytes), png_file) !=
       sizeof(sigbytes) ||
-      (!png_check_sig (sigbytes, sizeof(sigbytes))))
+      (png_sig_cmp (sigbytes, 0, sizeof(sigbytes))))
     return 0;
   else
     return 1;
