--- Imlib/load.c.orig	2004-09-21 02:23:20.000000000 +0200
+++ Imlib/load.c	2010-03-28 16:23:13.000000000 +0200
@@ -170,6 +176,7 @@
 #endif /* HAVE_LIBJPEG */
 
 #ifdef HAVE_LIBPNG
+#include <pngpriv.h>
 unsigned char      *
 _LoadPNG(ImlibData * id, FILE * f, int *w, int *h, int *t)
 {
@@ -192,7 +198,7 @@
       png_destroy_read_struct(&png_ptr, NULL, NULL);
       return NULL;
     }
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
     {
       png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
       return NULL;
@@ -1619,7 +1619,7 @@
     return 0;
   fread(buf, 1, 8, f);
   rewind(f);
-  return (int)png_check_sig(buf, 8);
+  return (int)!png_sig_cmp(buf, 0, 8);
 #else
   return 0;
 #endif
