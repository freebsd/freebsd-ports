* Fix zlib include
* Fix buffer size (obtained from teeworlds)
	* this buffer will contain compressed data + "IDAT" string + CRC32, but the latter two were not accounted
--- pnglite.c.orig	2019-01-05 19:00:10 UTC
+++ pnglite.c
@@ -5,7 +5,7 @@
 #define USE_ZLIB 1
 
 #if USE_ZLIB
-#include "../zlib/zlib.h"
+#include <zlib.h>
 #else
 #include "zlite.h"
 #endif
@@ -492,7 +492,7 @@ static int png_write_idats(png_t* png, unsigned char* 
 	(void)png_end_deflate;
 	(void)png_deflate;
 
-	chunk = png_alloc(size);
+	chunk = png_alloc(size + 8);
 	memcpy(chunk, "IDAT", 4);
 	
 	written = size;
