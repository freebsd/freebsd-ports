--- src/jpegread.c.orig	2011-06-22 20:04:32.000000000 +0200
+++ src/jpegread.c
@@ -417,7 +417,7 @@
     jpeg_read_scanlines( cinfop, row, 1 );
     row[0] += scanline_bytes;
   }
-  CAMLreturn0;
+  CAMLreturn(0);
 }
 
 value close_jpeg_file_for_read( jpegh )
