--- epi/image_png.cc.orig	2010-06-08 15:36:37.000000000 +0200
+++ epi/image_png.cc	2012-04-27 13:02:14.000000000 +0200
@@ -22,6 +22,7 @@
 
 #undef _SETJMP_H  // workaround for some weirdness in pngconf.h
 #include <png.h>
+#include <zlib.h>
 
 namespace epi
 {
@@ -96,7 +97,7 @@
 	/* set error handling since we are using the setjmp/longjmp method
 	 * (this is the normal method of doing things with libpng).
 	 */
-	if (setjmp(png_ptr->jmpbuf))
+	if (setjmp(png_jmpbuf(png_ptr)))
 	{
 		fprintf(stderr, "PNG_Load - Error loading PNG image !\n");
 		goto failed;
@@ -238,7 +239,7 @@
 	/* set error handling since we are using the setjmp/longjmp method
 	 * (this is the normal method of doing things with libpng).
 	 */
-	if (setjmp(png_ptr->jmpbuf))
+	if (setjmp(png_jmpbuf(png_ptr)))
 	{
 		fprintf(stderr, "PNG: Error loading PNG image !\n");
 		goto failed;
@@ -315,7 +318,7 @@
 	/* set error handling since we are using the setjmp/longjmp method
 	 * (this is the normal method of doing things with libpng).
 	 */
-	if (setjmp(png_ptr->jmpbuf))
+	if (setjmp(png_jmpbuf(png_ptr)))
 	{
 		fprintf(stderr, "PNG: Error saving PNG image !\n");
 		goto failed;
