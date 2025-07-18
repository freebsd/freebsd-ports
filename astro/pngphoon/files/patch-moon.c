--- moon.c.orig	2025-07-18 07:32:17 UTC
+++ moon.c
@@ -148,7 +148,7 @@ void mooncopy( image_t *image, moon_t *moondata, int c
       moonoff  = y * ( moondata->width ) / 8;
       imageoff = (y + yoffset) * image->xbytes + xoffset / 8;
 
-      shade = blackflag ? shade = 0xff : shades[shadeindex][y % 8];
+      shade = blackflag ? 0xff : shades[shadeindex][y % 8];
 
       /* finally, hack the bits */
       if( bytexleft == bytexright )
