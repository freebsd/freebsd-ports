--- src/file/file.cpp.orig
+++ src/file/file.cpp
@@ -56,13 +56,13 @@
 				// Date last edited		:	5/9/2002
 				CFramebuffer(const char *name,int width,int height,int numSamples,const char *samples,TDisplayParameterFunction findParameter) {
 					int			i;
-					char		*comment	=	NULL;
+					char		*comment	=	(char*)NULL;
 					float		*tmp;
 					float		worldToNDC[16];
 					float		worldToCamera[16];
 					char		*software;
 					char		desc[1024];
-					const char	*compression	=	NULL;
+					const char	*compression	=	(char*)NULL;
 
 					// Open the image file
 					image				=	TIFFOpen(name,"w");
@@ -189,7 +189,7 @@
 					scanlineUsage	=	new int[height];
 
 					for (i=0;i<height;i++) {
-						scanlines[i]		=	NULL;
+						scanlines[i]		=	(unsigned char*)NULL;
 						scanlineUsage[i]	=	width;
 					}
 
@@ -315,7 +315,7 @@
 								if (scanlines[lastSavedLine] != NULL) {
 									TIFFWriteScanline(image,scanlines[lastSavedLine],lastSavedLine,0);
 									delete [] scanlines[lastSavedLine];
-									scanlines[lastSavedLine]	=	NULL;
+									scanlines[lastSavedLine]	=	(unsigned char*)NULL;
 								}
 							} else {
 								break;
