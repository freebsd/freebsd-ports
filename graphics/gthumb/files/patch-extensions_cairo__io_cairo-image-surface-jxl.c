https://gitlab.gnome.org/GNOME/gthumb/-/issues/306

--- extensions/cairo_io/cairo-image-surface-jxl.c.orig	2022-04-03 18:38:59 UTC
+++ extensions/cairo_io/cairo-image-surface-jxl.c
@@ -234,18 +234,18 @@ _cairo_image_surface_create_from_jxl(GInputStream  *is
 
 		case JXL_DEC_COLOR_ENCODING:
 #if HAVE_LCMS2
-			if (JxlDecoderGetColorAsEncodedProfile(dec, &pixel_format, JXL_COLOR_PROFILE_TARGET_DATA, NULL) == JXL_DEC_SUCCESS)
+			if (JxlDecoderGetColorAsEncodedProfile(dec, JXL_COLOR_PROFILE_TARGET_DATA, NULL) == JXL_DEC_SUCCESS)
 				break;
 
 			{
 				gsize profile_size;
-				if (JxlDecoderGetICCProfileSize(dec, &pixel_format, JXL_COLOR_PROFILE_TARGET_DATA, &profile_size) > 0) {
+				if (JxlDecoderGetICCProfileSize(dec, JXL_COLOR_PROFILE_TARGET_DATA, &profile_size) > 0) {
 					g_message("Could not get ICC profile size.\n");
 					break;
 				}
 
 				guchar *profile_data = g_new(guchar, profile_size);
-				if (JxlDecoderGetColorAsICCProfile(dec, &pixel_format, JXL_COLOR_PROFILE_TARGET_DATA, profile_data, profile_size) > 0) {
+				if (JxlDecoderGetColorAsICCProfile(dec, JXL_COLOR_PROFILE_TARGET_DATA, profile_data, profile_size) > 0) {
 					g_message("Could not get ICC profile.\n");
 					g_free(profile_data);
 					break;
