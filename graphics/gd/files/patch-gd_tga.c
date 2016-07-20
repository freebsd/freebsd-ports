--- src/gd_tga.c.orig	2016-07-18 19:23:11 UTC
+++ src/gd_tga.c
@@ -99,7 +99,7 @@ BGD_DECLARE(gdImagePtr) gdImageCreateFro
 			if (tga->bits == TGA_BPP_24) {
 				*tpix = gdTrueColor(tga->bitmap[bitmap_caret + 2], tga->bitmap[bitmap_caret + 1], tga->bitmap[bitmap_caret]);
 				bitmap_caret += 3;
-			} else if (tga->bits == TGA_BPP_32 || tga->alphabits) {
+			} else if (tga->bits == TGA_BPP_32 && tga->alphabits) {
 				register int a = tga->bitmap[bitmap_caret + 3];
 
 				*tpix = gdTrueColorAlpha(tga->bitmap[bitmap_caret + 2], tga->bitmap[bitmap_caret + 1], tga->bitmap[bitmap_caret], gdAlphaMax - (a >> 1));
@@ -159,16 +159,13 @@ int read_header_tga(gdIOCtx *ctx, oTga *
 	printf("wxh: %i %i\n", tga->width, tga->height);
 #endif
 
-	switch(tga->bits) {
-	case 8:
-	case 16:
-	case 24:
-	case 32:
-		break;
-	default:
-		gd_error("bps %i not supported", tga->bits);
+	if (!((tga->bits == TGA_BPP_24 && tga->alphabits == 0)
+		|| (tga->bits == TGA_BPP_32 && tga->alphabits == 8)))
+	{
+		gd_error_ex(GD_WARNING, "gd-tga: %u bits per pixel with %u alpha bits not supported\n",
+			tga->bits, tga->alphabits);
+
 		return -1;
-		break;
 	}
 
 	tga->ident = NULL;
@@ -285,14 +285,23 @@ int read_image_tga( gdIOCtx *ctx, oTga *
 		buffer_caret = 0;
 
 		while( bitmap_caret < image_block_size ) {
-
+			
 			if ((decompression_buffer[buffer_caret] & TGA_RLE_FLAG) == TGA_RLE_FLAG) {
 				encoded_pixels = ( ( decompression_buffer[ buffer_caret ] & 127 ) + 1 );
 				buffer_caret++;
 
-				for (i = 0; i < encoded_pixels; i++) {
-					for (j = 0; j < pixel_block_size; j++, bitmap_caret++) {
-						tga->bitmap[ bitmap_caret ] = decompression_buffer[ buffer_caret + j ];
+				if (encoded_pixels != 0) {
+				
+					if (!((buffer_caret + (encoded_pixels * pixel_block_size)) < image_block_size)) {
+						gdFree( decompression_buffer );
+						gdFree( conversion_buffer );
+						return -1;
+					}
+
+					for (i = 0; i < encoded_pixels; i++) {
+						for (j = 0; j < pixel_block_size; j++, bitmap_caret++) {
+							tga->bitmap[ bitmap_caret ] = decompression_buffer[ buffer_caret + j ];
+						}
 					}
 				}
 				buffer_caret += pixel_block_size;
@@ -300,11 +309,20 @@ int read_image_tga( gdIOCtx *ctx, oTga *
 				encoded_pixels = decompression_buffer[ buffer_caret ] + 1;
 				buffer_caret++;
 
-				for (i = 0; i < encoded_pixels; i++) {
-					for( j = 0; j < pixel_block_size; j++, bitmap_caret++ ) {
-						tga->bitmap[ bitmap_caret ] = decompression_buffer[ buffer_caret + j ];
+				if (encoded_pixels != 0) {
+				
+					if (!((buffer_caret + (encoded_pixels * pixel_block_size)) < image_block_size)) {
+						gdFree( decompression_buffer );
+						gdFree( conversion_buffer );
+						return -1;
+					}
+
+					for (i = 0; i < encoded_pixels; i++) {
+						for( j = 0; j < pixel_block_size; j++, bitmap_caret++ ) {
+							tga->bitmap[ bitmap_caret ] = decompression_buffer[ buffer_caret + j ];
+						}
+						buffer_caret += pixel_block_size;
 					}
-					buffer_caret += pixel_block_size;
 				}
 			}
 		}

