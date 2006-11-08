--- src/modules/loaders/loader_jpeg.c.orig	Wed Nov  8 19:41:41 2006
+++ src/modules/loaders/loader_jpeg.c	Wed Nov  8 19:42:43 2006
@@ -104,8 +104,11 @@
         im->w = w = cinfo.output_width;
         im->h = h = cinfo.output_height;
 
-        if (cinfo.rec_outbuf_height > 16)
+        if (cinfo.rec_outbuf_height > 16 \
+	    || w < 1 || h < 1 || w > 16383 || h > 16383)
           {
+	     im->w = 0;
+	     im->h = 0;
              jpeg_destroy_decompress(&cinfo);
              fclose(f);
              return 0;
