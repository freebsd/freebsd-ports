--- GICBayer.cpp.orig	Mon Dec 23 04:19:54 2002
+++ GICBayer.cpp	Mon Dec 23 04:20:21 2002
@@ -236,7 +236,7 @@
 
 GICBayer_Green::GICBayer_Green(const unsigned char* imagedata, 
 			       int width, int height, 
-			       float maxerr=0)
+			       float maxerr)
   : GImageComponent(width,height,maxerr) {
 
   /* initialize arrays
@@ -428,7 +428,7 @@
 GICBayer_Red::GICBayer_Red(const unsigned char* imagedata, 
 				   int width, int height, 
 				   GImageComponent& green,
-				   float maxerr=0)
+				   float maxerr)
   : GImageComponent(width,height,maxerr) {
 
   if ((green.getWidth()!=w)||(green.getHeight()!=h)) {
@@ -617,7 +617,7 @@
 GICBayer_Blue::GICBayer_Blue(const unsigned char* imagedata, 
 			     int width, int height, 
 			     GImageComponent& green,
-			     float maxerr=0)
+			     float maxerr)
   : GImageComponent(width,height,maxerr) {
 
   if ((green.getWidth()!=w)||(green.getHeight()!=h)) {
