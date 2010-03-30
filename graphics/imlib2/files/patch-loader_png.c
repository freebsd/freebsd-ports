--- src/modules/loaders/loader_png.c.orig	2007-08-25 04:33:10.000000000 +0200
+++ src/modules/loaders/loader_png.c	2010-03-28 16:18:53.000000000 +0200
@@ -38,7 +38,7 @@
 
         /* if we haven't read the header before, set the header data */
         fread(buf, 1, PNG_BYTES_TO_CHECK, f);
-        if (!png_check_sig(buf, PNG_BYTES_TO_CHECK))
+        if (png_sig_cmp(buf, 0, PNG_BYTES_TO_CHECK))
           {
              fclose(f);
              return 0;
