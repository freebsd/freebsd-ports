--- tiff/tiffwrite.c.orig	Sat Feb  8 00:50:32 2003
+++ tiff/tiffwrite.c	Sat Feb  8 00:50:51 2003
@@ -34,15 +34,7 @@
 #else
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
 
