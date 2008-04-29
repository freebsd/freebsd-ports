--- src/world/bsp.cpp.orig	2008-04-25 19:38:11.000000000 +0400
+++ src/world/bsp.cpp	2008-04-29 00:26:31.000000000 +0400
@@ -22,6 +22,8 @@
 
 #define TESSELATION 10
 
+float swapBytes(float f);
+
 TextureSpec *getTextureSpec(const char *basename)
 {
 	// ignore this texture
