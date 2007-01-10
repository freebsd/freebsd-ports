--- renderer/rf_image.c.orig	Wed Jan 10 18:55:48 2007
+++ renderer/rf_image.c	Wed Jan 10 18:57:53 2007
@@ -44,7 +44,7 @@
 image_t			*r_lmTextures[R_MAX_LIGHTMAPS];
 static image_t	r_imageList[MAX_IMAGES];
 static image_t	*r_imageHashTree[MAX_IMAGE_HASH];
-static uint32	r_numImages;
+uint32	r_numImages;
 
 static byte		r_intensityTable[256];
 static byte		r_gammaTable[256];
