--- tga.c.orig	Thu Oct 13 04:41:39 2005
+++ tga.c	Thu Oct 13 04:42:08 2005
@@ -116,7 +116,7 @@
 	char colors[40];
 
 	if (hp->ImgType == TGA_Map || hp->ImgType == TGA_RLEMap)
-		sprintf(colors," with %d colors",hp->Length);
+		snprintf(colors,sizeof(colors)," with %d colors",hp->Length);
 	else
 		colors[0] = '\000';
 
