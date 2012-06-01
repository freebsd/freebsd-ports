--- Imlib/save.c.orig	2004-09-21 02:22:59.000000000 +0200
+++ Imlib/save.c	2012-04-27 07:19:57.000000000 +0200
@@ -342,7 +342,7 @@
 	      png_destroy_write_struct(&png_ptr, (png_infopp) NULL);
 	      return 0;
 	    }
-	  if (setjmp(png_ptr->jmpbuf))
+	  if (setjmp(png_jmpbuf(png_ptr)))
 	    {
 	      fclose(f);
 	      png_destroy_write_struct(&png_ptr, (png_infopp) NULL);
