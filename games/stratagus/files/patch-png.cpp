--- src/video/png.cpp.orig	2010-11-20 12:23:28.000000000 +0100
+++ src/video/png.cpp	2012-04-29 07:12:14.000000000 +0200
@@ -39,6 +39,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <png.h>
+#include <pngpriv.h>
 
 #include "stratagus.h"
 #include "video.h"
@@ -147,7 +148,7 @@
 	 * the normal method of doing things with libpng).  REQUIRED unless you
 	 * set up your own error handlers in png_create_read_struct() earlier.
 	 */
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		fprintf(stderr, "Error reading the PNG file.\n");
 		ret = -1;
 		goto done;
@@ -343,7 +344,7 @@
 		return;
 	}
 
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		/* If we get here, we had a problem reading the file */
 		fclose(fp);
 		png_destroy_write_struct(&png_ptr, &info_ptr);
