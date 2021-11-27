--- plugins/load-gdk/exiv2-colorspace.cpp.orig	2011-02-23 22:35:18 UTC
+++ plugins/load-gdk/exiv2-colorspace.cpp
@@ -22,6 +22,8 @@
 #include <iomanip>
 #include <exiv2/image.hpp>
 #include <exiv2/exif.hpp>
+#include <exiv2/version.hpp>
+#include <exiv2/error.hpp>
 #include <assert.h>
 #include "exiv2-colorspace.h"
 #include <math.h>
@@ -125,11 +127,11 @@ jpeg_fail:
 
 					int compression_type;
 					/* Extract embedded ICC profile */
-					if (info_ptr->valid & PNG_INFO_iCCP)
+					if (png_get_valid(png_ptr, info_ptr, TRUE) & PNG_INFO_iCCP)
 					{
 						png_uint_32 retval = png_get_iCCP (png_ptr, info_ptr,
 													(png_charpp) &icc_profile_title, &compression_type,
-													(png_charpp) &icc_profile, (png_uint_32*) &icc_profile_size);
+													(png_byte**) &icc_profile, (png_uint_32*) &icc_profile_size);
 						if (retval != 0)
 						{
 							RSIccProfile *icc = rs_icc_profile_new_from_memory((gchar*)icc_profile, icc_profile_size, TRUE);
