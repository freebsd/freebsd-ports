--- src/Core/Materials/OOPNGTextureLoader.m.orig	2014-06-30 08:50:36 UTC
+++ src/Core/Materials/OOPNGTextureLoader.m
@@ -31,9 +31,6 @@ SOFTWARE.
 #import "OOCPUInfo.h"
 #import "NSDataOOExtensions.h"
 
-void png_error(png_structp, png_const_charp) NO_RETURN_FUNC;
-
-
 static void PNGError(png_structp png, png_const_charp message);
 static void PNGWarning(png_structp png, png_const_charp message);
 static void PNGRead(png_structp png, png_bytep bytes, png_size_t size);
