--- texk/web2c/pdftexdir/writepng.c.orig	2005-02-03 17:16:39.000000000 +0100
+++ texk/web2c/pdftexdir/writepng.c	2012-04-27 09:06:18.000000000 +0200
@@ -22,6 +22,7 @@
 
 #include "ptexlib.h"
 #include "image.h"
+#include "pngpriv.h"
 
 static const char perforce_id[] = 
     "$Id: //depot/Build/source.development/TeX/texk/web2c/pdftexdir/writepng.c#5 $";
@@ -34,7 +35,7 @@
         pdftex_fail("libpng: png_create_read_struct() failed");
     if ((png_info(img) = png_create_info_struct(png_ptr(img))) == NULL)
         pdftex_fail("libpng: png_create_info_struct() failed");
-    if (setjmp(png_ptr(img)->jmpbuf))
+    if (setjmp(png_jmpbuf(png_ptr(img))))
         pdftex_fail("libpng: internal error");
     png_init_io(png_ptr(img), png_file);
     png_read_info(png_ptr(img), png_info(img));
