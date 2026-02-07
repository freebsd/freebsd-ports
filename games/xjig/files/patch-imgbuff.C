--- imgbuff.C.orig	Wed Jul 17 00:23:26 1996
+++ imgbuff.C	Tue Apr  7 15:34:33 1998
@@ -72,6 +72,7 @@
 
 
 XImage *ImageBuffer::Init(int w,int h,int bpp8) {
+
 	// w+=10; h+=10;
 	if (w>width||h>height) {
 		FreeData();
