--- reduce.c.orig	Thu Oct 13 04:36:44 2005
+++ reduce.c	Thu Oct 13 04:37:02 2005
@@ -178,7 +178,7 @@
 	/* get destination image */
 	depth = colorsToDepth(OutColors);
 	new_image = newRGBImage(image->width, image->height, depth);
-	sprintf(buf, "%s (%d colors)", image->title, OutColors);
+	snprintf(buf, sizeof(buf), "%s (%d colors)", image->title, OutColors);
 	new_image->title = dupString(buf);
 	new_image->gamma = image->gamma;
 
