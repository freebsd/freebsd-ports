--- interface/x_sherry.c.orig	2002-07-14 23:19:32.000000000 +0200
+++ interface/x_sherry.c	2012-04-27 13:12:58.000000000 +0200
@@ -34,6 +34,7 @@
 #endif
 #include <stdlib.h>
 #include <png.h>
+#include <pngpriv.h>
 
 #include "timidity.h"
 #include "common.h"
@@ -909,7 +910,7 @@
 	{
 	    if(png_get_valid(pngPtr, infoPtr, PNG_INFO_hIST))
 		png_get_hIST(pngPtr, infoPtr, &hist);
-	    png_set_dither(pngPtr, palette,
+	    png_set_quantize(pngPtr, palette,
 			   numPalette, MAX_SCREEN_COLORS, hist, 1);
 	}
     }
@@ -934,7 +935,7 @@
 		}
 	    }
 	}
-	png_set_dither(pngPtr, stdColorCube,
+	png_set_quantize(pngPtr, stdColorCube,
 		       6*7*6, MAX_SCREEN_COLORS,
 		       NULL, 1);
 	/*???*/
