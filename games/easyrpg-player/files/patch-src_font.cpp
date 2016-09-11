--- src/font.cpp.orig	2015-09-14 09:52:35 UTC
+++ src/font.cpp
@@ -145,7 +145,7 @@ BitmapRef ShinonomeFont::Glyph(unsigned 
 	assert(glyph);
 	size_t const width = glyph->is_full? FULL_WIDTH : HALF_WIDTH;
 
-	BitmapRef bm = Bitmap::Create(reinterpret_cast<void*>(NULL), width, HEIGHT, 0, DynamicFormat(8,8,0,8,0,8,0,8,0,PF::Alpha));
+	BitmapRef bm = Bitmap::Create(nullptr, width, HEIGHT, 0, DynamicFormat(8,8,0,8,0,8,0,8,0,PF::Alpha));
 	uint8_t* data = reinterpret_cast<uint8_t*>(bm->pixels());
 	int pitch = bm->pitch();
 	for(size_t y_ = 0; y_ < HEIGHT; ++y_)
@@ -194,7 +194,7 @@ BitmapRef FTFont::Glyph(unsigned glyph) 
 	int const width = ft_bitmap.width;
 	int const height = ft_bitmap.rows;
 
-	BitmapRef bm = Bitmap::Create(reinterpret_cast<void*>(NULL), width, height, 0, DynamicFormat(8,8,0,8,0,8,0,8,0,PF::Alpha));
+	BitmapRef bm = Bitmap::Create(nullptr, width, height, 0, DynamicFormat(8,8,0,8,0,8,0,8,0,PF::Alpha));
 	uint8_t* data = reinterpret_cast<uint8_t*>(bm->pixels());
 	int dst_pitch = bm->pitch();
 
