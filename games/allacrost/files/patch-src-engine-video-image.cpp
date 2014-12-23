--- src/engine/video/image.cpp.orig	2010-05-16 23:38:27 UTC
+++ src/engine/video/image.cpp
@@ -677,9 +677,9 @@ void ImageDescriptor::_GetPngImageInfo(c
 	png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND, NULL);
 
 	// grab the relevant data...
-	cols = info_ptr->width;
-	rows = info_ptr->height;
-	bpp = info_ptr->channels * 8;
+	cols = png_get_image_width(png_ptr, info_ptr);
+	rows = png_get_image_height(png_ptr, info_ptr);
+	bpp = png_get_channels(png_ptr, info_ptr) * 8;
 
 	// and clean up.
 	png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
