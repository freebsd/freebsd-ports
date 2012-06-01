--- win/vultures/util/tiletrans.c.orig	2006-06-06 21:23:19.000000000 +0200
+++ win/vultures/util/tiletrans.c	2012-05-03 20:12:10.000000000 +0200
@@ -9,6 +9,7 @@
 #include "tiletrans.h"
 
 #include "png.h"
+#include "pngpriv.h"
 #include "SDL_endian.h"
 
 #include "config.h"
@@ -130,7 +131,7 @@
 	if (info_ptr == NULL)
 	{
 		fclose(fp);
-		png_destroy_read_struct(&png_ptr, png_infopp_NULL, png_infopp_NULL);
+		png_destroy_read_struct(&png_ptr, NULL, NULL);
 		return 1;
 	}
 
@@ -138,7 +139,7 @@
 	if (setjmp(png_jmpbuf(png_ptr)))
 	{
 		/* Free all of the memory associated with the png_ptr and info_ptr */
-		png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL);
+		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
 		fclose(fp);
 		/* If we get here, we had a problem reading the file */
 		return 1;
@@ -181,7 +182,7 @@
 	/* At this point you have read the entire image */
 
 	/* clean up after the read, and free any memory allocated */
-	png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL);
+	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
 
 	/* close the file */
 	fclose(fp);
