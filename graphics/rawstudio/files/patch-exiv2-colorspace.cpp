--- plugins/load-gdk/exiv2-colorspace.cpp.orig	2011-02-23 23:35:18.000000000 +0100
+++ plugins/load-gdk/exiv2-colorspace.cpp	2012-05-12 12:15:07.000000000 +0200
@@ -26,6 +26,7 @@
 #include "exiv2-colorspace.h"
 #include <math.h>
 #include <png.h>
+#include <pngpriv.h>
 #include <jpeglib.h>
 
 #ifndef EXIV2_TEST_VERSION
@@ -129,7 +130,7 @@
 					{
 						png_uint_32 retval = png_get_iCCP (png_ptr, info_ptr,
 													(png_charpp) &icc_profile_title, &compression_type,
-													(png_charpp) &icc_profile, (png_uint_32*) &icc_profile_size);
+													(png_byte**) (&icc_profile), (png_uint_32*) &icc_profile_size);
 						if (retval != 0)
 						{
 							RSIccProfile *icc = rs_icc_profile_new_from_memory((gchar*)icc_profile, icc_profile_size, TRUE);
