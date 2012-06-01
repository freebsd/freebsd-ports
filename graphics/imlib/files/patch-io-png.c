--- gdk_imlib/io-png.c.orig	2002-03-04 18:06:29.000000000 +0100
+++ gdk_imlib/io-png.c	2012-04-24 23:11:43.000000000 +0200
@@ -5,6 +5,7 @@
 
 #ifdef HAVE_LIBPNG
 #include <png.h>
+#include <pngpriv.h>
 
 unsigned char      *
 loader_png (FILE * f, int *w, int *h, int *t)
@@ -40,7 +41,7 @@
       return NULL;
     }
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
     {
       png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
       return NULL;
@@ -275,7 +276,7 @@
       return NULL;
     }
   
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
     {
       png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
       return NULL;
@@ -440,7 +441,7 @@
 		return NULL;
 	}
 	
-	if (setjmp(png_ptr->jmpbuf))
+	if (setjmp(png_jmpbuf(png_ptr)))
 	{
 		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
 		return NULL;
@@ -635,7 +636,7 @@
 	      png_destroy_write_struct(&png_ptr, (png_infopp) NULL);
 	      return 0;
 	    }
-	  if (setjmp(png_ptr->jmpbuf))
+	  if (setjmp(png_jmpbuf(png_ptr)))
 	    {
 	      fclose(f);
 	      png_destroy_write_struct(&png_ptr, (png_infopp) NULL);
