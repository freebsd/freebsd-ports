--- src/helper/png-write.c.orig	2004-02-09 20:01:16.000000000 +0100
+++ src/helper/png-write.c	2012-05-09 12:54:09.000000000 +0200
@@ -111,7 +111,7 @@
 	/* Set error handling.  REQUIRED if you aren't supplying your own
 	 * error hadnling functions in the png_create_write_struct() call.
 	 */
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		/* If we get here, we had a problem reading the file */
 		fclose(fp);
 		png_destroy_write_struct(&png_ptr, &info_ptr);
@@ -282,7 +282,7 @@
 	/* Set error handling.  REQUIRED if you aren't supplying your own
 	 * error hadnling functions in the png_create_write_struct() call.
 	 */
-	if (setjmp (png_ptr->jmpbuf)) {
+	if (setjmp (png_jmpbuf(png_ptr))) {
 		/* If we get here, we had a problem reading the file */
 		fclose (fp);
 		unlink (filename);
@@ -370,7 +370,7 @@
 
 		h = MIN (height - r, 64);
 		n = get_rows ((const unsigned char **) row_pointers, r, h, data);
-		if (!n) longjmp (png_ptr->jmpbuf, 1);
+		if (!n) longjmp (png_jmpbuf(png_ptr), 1);
 		png_write_rows (png_ptr, row_pointers, n);
 		r += n;
 	}
