--- GImageComponent.cpp.orig	Mon Dec 23 04:19:27 2002
+++ GImageComponent.cpp	Mon Dec 23 04:19:39 2002
@@ -283,7 +283,7 @@
 
 GImageComponent0::GImageComponent0(const unsigned char* imagedata, 
 				   int width, int height, 
-				   float maxerr=0)
+				   float maxerr)
   : GImageComponent(width,height,maxerr) {
 
   int itter;
