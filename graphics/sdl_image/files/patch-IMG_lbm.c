--- IMG_lbm.c	2007/07/20 04:37:11	3341
+++ IMG_lbm.c	2008/01/03 20:05:34	3521
@@ -28,6 +28,7 @@
    EHB and HAM (specific Amiga graphic chip modes) support added by Marc Le Douarain
    (http://www.multimania.com/mavati) in December 2003.
    Stencil and colorkey fixes by David Raulo (david.raulo AT free DOT fr) in February 2004.
+   Buffer overflow fix in RLE decompression by David Raulo in January 2008.
 */
 
 #include <stdio.h>
@@ -328,7 +329,7 @@
 						count ^= 0xFF;
 						count += 2; /* now it */
 
-						if ( !SDL_RWread( src, &color, 1, 1 ) )
+						if ( ( count > remainingbytes ) || !SDL_RWread( src, &color, 1, 1 ) )
 						{
 						   error="error reading BODY chunk";
 							goto done;
@@ -339,7 +340,7 @@
 					{
 						++count;
 
-						if ( !SDL_RWread( src, ptr, count, 1 ) )
+						if ( ( count > remainingbytes ) || !SDL_RWread( src, ptr, count, 1 ) )
 						{
 						   error="error reading BODY chunk";
 							goto done;
