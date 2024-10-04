--- OpenEXR_CTL/exrdpx/exrToDpx.cpp.orig	2024-01-04 19:41:17 UTC
+++ OpenEXR_CTL/exrdpx/exrToDpx.cpp
@@ -169,13 +169,13 @@ writePixels
 	    const Rgba &pixel = pixels[y][x];
 
 	    unsigned int r =
-		(unsigned int) (clamp (float (pixel.r), 0.0f, 1023.0f) + 0.5f);
+		(unsigned int) (std::clamp (float (pixel.r), 0.0f, 1023.0f) + 0.5f);
 
 	    unsigned int g =
-		(unsigned int) (clamp (float (pixel.g), 0.0f, 1023.0f) + 0.5f);
+		(unsigned int) (std::clamp (float (pixel.g), 0.0f, 1023.0f) + 0.5f);
 
 	    unsigned int b =
-		(unsigned int) (clamp (float (pixel.b), 0.0f, 1023.0f) + 0.5f);
+		(unsigned int) (std::clamp (float (pixel.b), 0.0f, 1023.0f) + 0.5f);
 
 	    unsigned int word = (r << 22) | (g << 12) | (b << 2);
 
