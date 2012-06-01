--- src/af/util/xp/ut_png.cpp.orig	2010-04-14 23:50:11.000000000 +0200
+++ src/af/util/xp/ut_png.cpp	2012-04-28 06:58:49.000000000 +0200
@@ -71,7 +71,7 @@
 	 * the normal method of doing things with libpng).  REQUIRED unless you
 	 * set up your own error handlers in the png_create_read_struct() earlier.
 	 */
-	if (setjmp(png_ptr->jmpbuf))
+	if (setjmp(png_jmpbuf(png_ptr)))
 	{
 		/* Free all of the memory associated with the png_ptr and info_ptr */
 		png_destroy_read_struct(&png_ptr, &info_ptr, static_cast<png_infopp>(NULL));
