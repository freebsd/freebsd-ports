--- util/giftext.c.orig	Mon Oct 10 08:08:51 2005
+++ util/giftext.c	Mon Aug 28 17:01:18 2006
@@ -136,5 +136,5 @@
 	printf("\tColorResolution = %d, BitsPerPixel = %d, BackGround = %d.\n",
 	       GifFile->SColorResolution,
-	       GifFile->SColorMap->BitsPerPixel,
+	       GifFile->SColorMap?GifFile->SColorMap->BitsPerPixel:0,
 	       GifFile->SBackGroundColor);
 	if (GifFile->SColorMap)
