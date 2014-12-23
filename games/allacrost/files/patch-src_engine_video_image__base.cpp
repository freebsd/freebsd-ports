--- src/engine/video/image_base.cpp.orig	2010-05-16 23:38:27 UTC
+++ src/engine/video/image_base.cpp
@@ -259,9 +259,9 @@ bool ImageMemory::_LoadPngImage(const st
 	uint8** row_pointers = png_get_rows(png_ptr, info_ptr);
 
 	// copy metadata
-	width = info_ptr->width;
-	height = info_ptr->height;
-	pixels = malloc(info_ptr->width * info_ptr->height * 4);
+	width = png_get_image_width(png_ptr, info_ptr);
+	height = png_get_image_height(png_ptr, info_ptr);
+	pixels = malloc(width * height * 4);
 
 	// check that we were able to allocate enough memory for the PNG
 	if (pixels == NULL) {
@@ -274,18 +274,21 @@ bool ImageMemory::_LoadPngImage(const st
 	// convert the damn thing so that it works in our format
 	// this is mostly just byteswapping and adding extra data - we want everything in four channels
 	// for the moment, anyway
-	uint32 bpp = info_ptr->channels;
+	uint32 bpp = png_get_channels(png_ptr, info_ptr);
 	uint8* img_pixel = NULL;
 	uint8* dst_pixel = NULL;
 
-	if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE) {
+	if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE) {
 		// colours come from a palette - for this colour type, we have to look up the colour from the palette
+		png_colorp palette;
+		int num_palette;
+		png_get_PLTE(png_ptr, info_ptr, &palette, &num_palette);
 		png_color c;
-		for (uint32 y = 0; y < info_ptr->height; y++) {
-			for (uint32 x = 0; x < info_ptr->width; x++) {
+		for (uint32 y = 0; y < height; y++) {
+			for (uint32 x = 0; x < width; x++) {
 				img_pixel = row_pointers[y] + (x * bpp);
-				dst_pixel = ((uint8*)pixels) + ((y * info_ptr->width) + x) * 4;
-				c = info_ptr->palette[img_pixel[0]];
+				dst_pixel = ((uint8*)pixels) + ((y * width) + x) * 4;
+				c = palette[img_pixel[0]];
 
 				dst_pixel[0] = c.red;
 				dst_pixel[1] = c.green;
@@ -295,10 +298,10 @@ bool ImageMemory::_LoadPngImage(const st
 		}
 	}
 	else if (bpp == 1) {
-		for (uint32 y = 0; y < info_ptr->height; y++) {
-			for (uint32 x = 0; x < info_ptr->width; x++) {
+		for (uint32 y = 0; y < height; y++) {
+			for (uint32 x = 0; x < width; x++) {
 				img_pixel = row_pointers[y] + (x * bpp);
-				dst_pixel = ((uint8*)pixels) + ((y * info_ptr->width) + x) * 4;
+				dst_pixel = ((uint8*)pixels) + ((y * width) + x) * 4;
 				dst_pixel[0] = img_pixel[0];
 				dst_pixel[1] = img_pixel[0];
 				dst_pixel[2] = img_pixel[0];
@@ -307,10 +310,10 @@ bool ImageMemory::_LoadPngImage(const st
 		}
 	}
 	else if (bpp == 3) {
-		for (uint32 y = 0; y < info_ptr->height; y++) {
-			for (uint32 x = 0; x < info_ptr->width; x++) {
+		for (uint32 y = 0; y < height; y++) {
+			for (uint32 x = 0; x < width; x++) {
 				img_pixel = row_pointers[y] + (x * bpp);
-				dst_pixel = ((uint8*)pixels) + ((y * info_ptr->width) + x) * 4;
+				dst_pixel = ((uint8*)pixels) + ((y * width) + x) * 4;
 				dst_pixel[0] = img_pixel[0];
 				dst_pixel[1] = img_pixel[1];
 				dst_pixel[2] = img_pixel[2];
@@ -319,10 +322,10 @@ bool ImageMemory::_LoadPngImage(const st
 		}
 	}
 	else if (bpp == 4) {
-		for (uint32 y = 0; y < info_ptr->height; y++) {
-			for (uint32 x = 0; x < info_ptr->width; x++) {
+		for (uint32 y = 0; y < height; y++) {
+			for (uint32 x = 0; x < width; x++) {
 				img_pixel = row_pointers[y] + (x * bpp);
-				dst_pixel = ((uint8*)pixels) + ((y * info_ptr->width) + x) * 4;
+				dst_pixel = ((uint8*)pixels) + ((y * width) + x) * 4;
 				dst_pixel[0] = img_pixel[0];
 				dst_pixel[1] = img_pixel[1];
 				dst_pixel[2] = img_pixel[2];
