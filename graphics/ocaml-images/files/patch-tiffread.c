--- tiff/tiffread.c.orig	Sat Feb  8 00:49:46 2003
+++ tiff/tiffread.c	Sat Feb  8 00:50:10 2003
@@ -37,15 +37,7 @@
 typedef	char int8;
 #endif
 
-#ifdef uint8
 typedef	unsigned char uint8;
-#endif
-#ifdef int16
-typedef	short int16;
-#endif
-#ifdef uint16
-typedef	unsigned short uint16;	/* sizeof (uint16) must == 2 */
-#endif
 
 #include <tiffio.h>
 
