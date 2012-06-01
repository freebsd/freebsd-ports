--- lib/EZ_Png.c.orig	1999-12-03 22:49:22.000000000 +0100
+++ lib/EZ_Png.c	2012-04-27 07:56:25.000000000 +0200
@@ -37,6 +37,7 @@
 #if defined(HAVE_LIBPNG) && defined(PNG_SUPPORT)
 #undef EXTERN 
 #include <png.h>
+#include <pngpriv.h>
 
 static int EZ_ReadPng(fname, w_ret, h_ret, p_ret, rgb_return)
      char *fname;
@@ -61,7 +62,7 @@
       fclose(fp);
       return(0);
     }
-  if(setjmp(png_ptr->jmpbuf))
+  if(setjmp(png_jmpbuf(png_ptr)))
     {
       fclose(fp);
       png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
