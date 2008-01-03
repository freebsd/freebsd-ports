--- src/world/bsp.cpp.orig	2007-05-22 00:26:13.000000000 +0400
+++ src/world/bsp.cpp	2007-12-31 19:23:29.000000000 +0300
@@ -22,6 +22,8 @@
 
 #define TESSELATION 10
 
+float swapBytes(float f);
+
 TextureSpec *getTextureSpec(char *basename)
 {
 	// ignore this texture
