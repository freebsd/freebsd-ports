--- src/modules/loaders/png/evas_image_load_png.c.orig	2007-10-28 11:35:13.000000000 +0100
+++ src/modules/loaders/png/evas_image_load_png.c	2010-04-01 07:26:03.000000000 +0200
@@ -44,7 +44,7 @@
 	fclose(f);
 	return 0;
      }
-   if (!png_check_sig(buf, PNG_BYTES_TO_CHECK))
+   if (png_sig_cmp(buf, 0, PNG_BYTES_TO_CHECK))
      {
 	fclose(f);
 	return 0;
@@ -121,7 +121,7 @@
 
    /* if we havent read the header before, set the header data */
    fread(buf, 1, PNG_BYTES_TO_CHECK, f);
-   if (!png_check_sig(buf, PNG_BYTES_TO_CHECK))
+   if (png_sig_cmp(buf, 0, PNG_BYTES_TO_CHECK))
      {
 	fclose(f);
 	return 0;
