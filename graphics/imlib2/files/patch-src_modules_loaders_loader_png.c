--- src/modules/loaders/loader_png.c.orig	Wed Nov  8 19:47:13 2006
+++ src/modules/loaders/loader_png.c	Wed Nov  8 19:48:04 2006
@@ -83,6 +83,13 @@
         png_get_IHDR(png_ptr, info_ptr, (png_uint_32 *) (&w32),
                      (png_uint_32 *) (&h32), &bit_depth, &color_type,
                      &interlace_type, NULL, NULL);
+        if (w32 < 1 || h32 < 1 || w32 > 16383 || h32 > 16383) {
+              png_read_end(png_ptr, info_ptr);
+              png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) NULL);
+              fclose(f);
+              return 0;
+        }
+
         im->w = (int)w32;
         im->h = (int)h32;
         if (color_type == PNG_COLOR_TYPE_PALETTE)
