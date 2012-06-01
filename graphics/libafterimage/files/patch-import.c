--- import.c.orig	2011-01-15 06:52:22.000000000 +0100
+++ import.c	2012-05-04 18:57:46.000000000 +0200
@@ -40,6 +40,7 @@
 # else
 #  include <png.h>
 # endif
+# include <pngpriv.h>
 #else
 # include <setjmp.h>
 # ifdef HAVE_JPEG
@@ -1251,7 +1252,7 @@
 			 * the normal method of doing things with libpng).  REQUIRED unless you
 			 * set up your own error handlers in the png_create_read_struct() earlier.
 			 */
-			if ( !setjmp (png_ptr->jmpbuf))
+			if ( !setjmp (png_jmpbuf(png_ptr)))
 			{
 				ASFlagType rgb_flags = ASStorage_RLEDiffCompress|ASStorage_32Bit ;
 
