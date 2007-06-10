--- f_readjpg.c.orig	Tue Jul 26 09:39:59 2005
+++ f_readjpg.c
@@ -178,8 +178,10 @@
 	pict->pic_cache->bit_size.x = cinfo.image_width;
 	pict->pic_cache->bit_size.y = cinfo.image_height;
 	if ((pict->pic_cache->bitmap = (unsigned char *) 
-	     malloc(cinfo.image_width * cinfo.image_height)) == NULL)
-		error_exit("Can't alloc memory for JPEG image");
+	  malloc(cinfo.image_width * cinfo.image_height)) == NULL) {
+	    file_msg("Can't alloc memory for JPEG image");
+	    longjmp(jerr.setjmp_buffer, 1);
+	}
 	bitmapptr = pict->pic_cache->bitmap;
 
 	/* Step 4: set parameters for decompression */
