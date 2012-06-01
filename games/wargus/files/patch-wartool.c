--- wartool.c.orig	2010-11-22 22:44:24.000000000 +0100
+++ wartool.c	2012-05-05 12:37:53.000000000 +0200
@@ -62,6 +62,8 @@
 #endif
 #include <ctype.h>
 #include <png.h>
+#include <zlib.h>
+#include <pngpriv.h>
 
 #include "endian.h"
 #include "xmi2mid.h"
@@ -1876,7 +1878,7 @@
 		return 1;
 	}
 
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		// FIXME: must free buffers!!
 		png_destroy_write_struct(&png_ptr, &info_ptr);
 		fclose(fp);
