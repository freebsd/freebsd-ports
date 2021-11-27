--- plugins/output-pngfile/output-pngfile.c.orig	2011-03-26 01:52:29 UTC
+++ plugins/output-pngfile/output-pngfile.c
@@ -23,6 +23,7 @@
 #include <gettext.h>
 #include "config.h"
 #include <png.h>
+#include <zlib.h>
 
 #define RS_TYPE_PNGFILE (rs_pngfile_type)
 #define RS_PNGFILE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RS_TYPE_PNGFILE, RSPngfile))
@@ -198,7 +199,7 @@ execute(RSOutput *output, RSFilter *filter)
 		rs_icc_profile_get_data(profile, &data, &data_length);
 
 		// FIXME: Insert correct profile name
-		png_set_iCCP(png_ptr, info_ptr, "Profile name", PNG_COMPRESSION_TYPE_BASE, data, data_length);
+		png_set_iCCP(png_ptr, info_ptr, "Profile name", PNG_COMPRESSION_TYPE_BASE, (png_const_bytep)data, data_length);
 		if (pngfile->save16bit)
 			png_set_gAMA(png_ptr, info_ptr, 1.0);
 	}
