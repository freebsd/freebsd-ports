--- png.c.orig	2006-08-20 23:04:06.000000000 +0200
+++ png.c	2012-05-04 13:03:57.000000000 +0200
@@ -1,5 +1,6 @@
 #include "filter.h"
 #include "png.h"
+#include "pngpriv.h"
 
 
 
@@ -56,7 +57,7 @@
    	}
 
   	/* set error handling */
-   	if (setjmp(png_ptr->jmpbuf))
+   	if (setjmp(png_jmpbuf(png_ptr)))
    	{
       /* If we get here, we had a problem reading the file */
       fclose(outfile);
@@ -165,7 +166,7 @@
    	}
 
    	/* set error handling if you are using the setjmp/longjmp method */
-   	if (setjmp(png_ptr->jmpbuf))
+   	if (setjmp(png_jmpbuf(png_ptr)))
    	{
       	/* Free all of the memory associated with the png_ptr and info_ptr */
       	png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
