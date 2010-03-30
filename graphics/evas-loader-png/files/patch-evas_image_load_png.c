--- src/modules/loaders/png/evas_image_load_png.c.orig	2007-10-28 11:35:13.000000000 +0100
+++ src/modules/loaders/png/evas_image_load_png.c	2010-03-30 14:16:48.000000000 +0200
@@ -44,7 +44,7 @@
 	fclose(f);
 	return 0;
      }
-   if (!png_check_sig(buf, PNG_BYTES_TO_CHECK))
+   if (png_sig_cmp(buf, 0, PNG_BYTES_TO_CHECK))
      {
 	fclose(f);
 	return 0;
