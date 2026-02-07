--- libg19draw.c.orig	2010-04-11 03:29:42.000000000 +0200
+++ libg19draw.c	2011-04-16 08:41:30.000000000 +0200
@@ -21,22 +21,211 @@
 #include <stdlib.h>
 #include <string.h>
 
-#include "config.h"
+#include <config.h>
 #include "libg19draw.h"
 
+
 #ifdef FT2_SUPPORT
+
+#include "libg19draw.h"
+
 #include <ft2build.h>
 #include FT_FREETYPE_H
 #include FT_BITMAP_H
 
-static FT_Library ft_lib;
-static FT_Face ft_face;
-static int ft_width;
-static int ft_height;
-static int ft_space;
-static unsigned int ft_color;
+/**
+ * Creates a new G19Font
+ * 
+ * @param ttf_path path to the ttf file
+ * @param width width of text
+ * @param height height of text
+ * @param space space between characters in pixels
+ * @param color an unsigned int that hold the color; G19Color() or G19ColorA() can be used
+ * 
+ * @return pointer to a G19Font or NULL on error
+ **/
+G19Font * g19_font_new(char * ttf_path, int width, int height, int space, unsigned int color)
+{
+	G19Font * font = malloc(sizeof(G19Font));
+	
+	if(FT_Init_FreeType(&font -> lib))
+		return NULL;
+	
+	if(FT_New_Face(font -> lib, ttf_path, 0, &font -> face))
+	{
+		FT_Done_FreeType(font -> lib);
+		return NULL;
+	}
+	
+	if(FT_Set_Pixel_Sizes(font -> face, width, height))
+	{
+		FT_Done_Face(font -> face);
+		FT_Done_FreeType(font -> lib);
+		return NULL;
+	}
+	
+	font -> width = width;
+	font -> height = height;
+	font -> space = space;
+	font -> color = color;
+	
+	return font;
+}
+
+/**
+ * Sets the character size on the G19Font
+ * 
+ * @param font a pointer G19Font
+ * @param width width of text
+ * @param height height of text
+ **/
+void g19_font_set_size(G19Font * font, int width, int height)
+{
+	if(font == NULL)
+		return;
+	
+	FT_Set_Pixel_Sizes(font -> face, width, height);
+	
+	font -> width = width;
+	font -> height = height;
+}
+
+/**
+ * Sets the character spacing on the G19Font
+ * 
+ * @param font a pointer G19Font
+ * @param space between characters in pixels
+ **/
+void g19_font_set_space(G19Font * font, int space)
+{
+	if(font == NULL)
+		return;
+	
+	font -> space = space;
+}
+
+/**
+ * Sets the color on the G19Font
+ * 
+ * @param font a pointer G19Font
+ * @param color the color to set the text; G19Color() or G19ColorA() can be used
+ **/
+void g19_font_set_color(G19Font * font, unsigned int color)
+{
+	if(font == NULL)
+		return;
+	
+	font -> color = color;
+}
+
+/**
+ * Draws text on the G19Draw with G19Font
+ * 
+ * @param font a pointer G19Font
+ * @param draw a pointer G19Draw
+ * @param x x coordinate of the upper-left
+ * @param y y coordinate of the upper-left
+ * @param text pointer to an array of chars to be drawn
+ * 
+ * @return the number of characters written or < 0 on error
+ **/
+int g19_font_draw(G19Font * font, G19Draw * draw, int x, int y, char * text)
+{
+	if((font == NULL) || (draw == NULL))
+		return -1;
+	
+	if((font -> lib == NULL) || (font -> face == NULL))
+		return -1;
+	
+	int res, i;
+	FT_GlyphSlot slot;
+	FT_UInt gi;
+	
+	slot = font -> face -> glyph;
+	
+	for(i = 0; i < strlen(text); i++)
+	{
+		gi = FT_Get_Char_Index(font -> face, text[i]);
+		
+		if(gi == 0)
+			continue;
+		
+		res = FT_Load_Char(font -> face, (FT_ULong) text[i], FT_LOAD_DEFAULT);
+		if(res)
+			continue;
+		
+		res = FT_Render_Glyph(slot, FT_RENDER_MODE_NORMAL);
+		if(res)
+			continue;
+		
+		if(slot -> bitmap.width < 1)
+		{
+			x += (font -> width / 2);
+			continue;
+		}
+		
+		x += font -> space;
+		
+		if((x + slot -> bitmap.width) >= draw -> width)
+			break;
+		
+		int xx, yy;
+		unsigned char tc;
+		unsigned int bcolor, fcolor;
+		int r, g, b;
+		
+		for(yy = 0; yy < slot -> bitmap.rows; yy++)
+		{
+			for(xx = 0; xx < slot -> bitmap.width; xx++)
+			{
+				tc = slot -> bitmap.buffer[(yy * slot -> bitmap.width) + xx];
+				
+				if(tc == 0)
+					continue;
+				
+				bcolor = g19_draw_get_pixel(draw, xx, yy);
+				
+				r = G19R(bcolor) + (((G19R(font -> color) - G19R(bcolor)) * tc) / 256);
+				g = G19G(bcolor) + (((G19G(font -> color) - G19G(bcolor)) * tc) / 256);
+				b = G19B(bcolor) + (((G19B(font -> color) - G19B(bcolor)) * tc) / 256);
+				
+				fcolor = G19Color(r, g, b);
+				
+				g19_draw_set_pixel(draw, slot -> bitmap_left + xx + x,
+								  (font -> height - slot -> bitmap_top) + yy + y, fcolor);
+			}
+		}
+		
+		x += slot -> bitmap.width;
+	}
+	
+	return i;
+}
+
+/**
+ * Frees a G19Font
+ * 
+ * @param font a pointer G19Font
+ **/
+void g19_font_free(G19Font * font)
+{
+	if(font == NULL)
+		return;
+	
+	if(font -> face != NULL)
+		FT_Done_Face(font -> face);
+	
+	if(font -> lib != NULL)
+		FT_Done_FreeType(font -> lib);
+	
+	free(font);
+}
+
 #endif
 
+
+
+
 /**
  * Creates a new G19Draw
  * 
@@ -49,13 +238,13 @@
 {
 	G19Draw * draw;
 	
-	draw = (G19Draw *) malloc(sizeof(G19Draw));
+	draw = malloc(sizeof(G19Draw));
 	
 	draw -> width = width;
 	draw -> height = height;
 	draw -> size = width * height * 4;
 	
-	draw -> data = (unsigned char *) malloc(draw -> size);
+	draw -> data = malloc(draw -> size);
 	memset(draw -> data, 0x00, draw -> size);
 	
 	return draw;
@@ -143,9 +332,9 @@
 	
 	fseek(file, doff, SEEK_SET);
 	
-	for(x = 0; x < width; x++)
+	for(y = height - 1; y > 0; y--)
 	{
-		for(y = 0; y < height; y++)
+		for(x = 0; x < width; x++)
 		{
 			if(bits == 24)
 			{
@@ -158,7 +347,7 @@
 				color = G19ColorA(buffer[2], buffer[1], buffer[0], buffer[3]);
 			}
 			
-			g19_draw_set_pixel(draw, y + (width - height), ((width + (height - width)) - 1) - x, color);
+			g19_draw_set_pixel(draw, x, y, color);
 		}
 	}
 	
@@ -184,6 +373,98 @@
 }
 
 /**
+ * Save a G19Draw to an 24-bit bitmap
+ * 
+ * @param draw pointer to a G19Draw
+ * @param path path to save the image to
+ * 
+ * @return 0 on success; non-zero on error
+ **/
+int g19_draw_to_bmp(G19Draw * draw, char * path)
+{
+	FILE * fp;
+	unsigned char * bmp;
+	int data_size, bmp_size;
+	int d ,x, y;
+	unsigned int color;
+	
+	fp = fopen(path, "wb");
+	if(fp == NULL)
+		return -1;
+	
+	data_size = (draw -> width * draw -> height) * 4;
+	bmp_size = data_size + 54;
+	
+	bmp = malloc(bmp_size);
+	memset(bmp, 0, bmp_size);
+	
+	bmp[0x0]	= 0x42;
+	bmp[0x1]	= 0x4d;
+	bmp[0xa]	= 0x36;
+	bmp[0xe]	= 0x28;
+	bmp[0x1a]	= 0x1;
+	bmp[0x1c]	= 0x20;
+	
+	d = 2835;
+	
+	memcpy(bmp + 0x2, &bmp_size, 4);
+	memcpy(bmp + 0x12, &draw -> width, 4);
+	memcpy(bmp + 0x16, &draw -> height, 4);
+	memcpy(bmp + 0x22, &data_size, 4);
+	memcpy(bmp + 0x26, &d, 4);
+	memcpy(bmp + 0x2a, &d, 4);
+	
+	d = 0;
+	for(y = draw -> height - 1; y > 0; y--)
+	{
+		for(x = 0; x < draw -> width; x++)
+		{
+			color = g19_draw_get_pixel(draw, x, y);
+			color = G19ColorA(G19B(color), G19G(color),
+							  G19R(color), 0xff);
+			
+			memcpy(bmp + ((d * 4) + 0x36), &color, 4);
+			d++;
+		}
+	}
+	
+	fwrite(bmp, 1, bmp_size, fp);
+	free(bmp);
+	
+	fclose(fp);
+	
+	return 0;
+}
+
+/**
+ * Resizes a G19Draw
+ * 
+ * @param width width in pixels to resize to
+ * @param height height in pixels to resize to
+ * @param color the base color of the new image; G19Color() or G19ColorA() can be used
+ * @param free_old free the allocated memory of the old old G19Draw; 0 for no, 1 for yes
+ * 
+ * @return a pointer to the new G19Draw or NULL on error
+ **/
+G19Draw * g19_draw_resize(G19Draw * draw, int width, int height, unsigned int color, int free_old)
+{
+	if(draw == NULL)
+		return NULL;
+	
+	if((width < 1) || (height < 1))
+		return NULL;
+	
+	G19Draw * resize = g19_draw_new(width, height);
+	g19_draw_fill(resize, color);
+	g19_draw_insert(resize, draw, 0, 0);
+	
+	if(free_old)
+		g19_draw_free(draw);
+	
+	return resize;
+}
+
+/**
  * Insert a G19Draw onto another G19Draw
  * 
  * @param draw pointer to the destination G19Draw
@@ -242,7 +523,7 @@
 	int x, y;
 	int dd, id;
 	unsigned char d1[4], d2[4];
-	int r, g, b;
+	unsigned char r, g, b;
 	unsigned int color;
 	
 	ex = ((ix + idraw -> width) < draw -> width) ? idraw -> width : (draw -> width - ix);
@@ -378,7 +659,7 @@
 	
 	err = dx / 2;
 	y = y1;
-	ystep = (y1 < y2) ? 1 : 0;
+	ystep = (y1 < y2) ? 1 : -1;
 	
 	for(x = x1; x < x2; x++)
 	{
@@ -388,7 +669,7 @@
 			g19_draw_set_pixel(draw, x, y, color);
 		
 		err = err - dy;
-		if(!err)
+		if(err < 0)
 		{
 			y = y + ystep;
 			err = err + dx;
@@ -417,7 +698,7 @@
 		g19_draw_line(draw, left, top, right, top, color);
 		g19_draw_line(draw, left, bottom, right, bottom, color);
 		g19_draw_line(draw, left, top, left, bottom, color);
-		g19_draw_line(draw, right, top, right, bottom, color);
+		g19_draw_line(draw, right, top, right, bottom + 1, color);
 		
 		return;
 	}
@@ -494,159 +775,3 @@
 	}
 	
 }
-
-/**
- * Draws a slot from FreeType on the G19Draw
- * 
- * @param draw a pointer G19Draw
- * @param fslot G19FontSlot that holds the FreeType slot data
- **/
-void g19_draw_ft_slot(G19Draw * draw, G19FontSlot * fslot, int x, int y)
-{
-	int xx, yy;
-	unsigned char tc;
-	unsigned int fcolor;
-	
-	if(draw == NULL)
-		return;
-	
-	G19FontBitmap * bitmap = fslot -> bitmap;
-	
-	G19Draw * tdraw = g19_draw_new(fslot -> width, fslot -> bitmap_top + fslot -> height);
-	g19_draw_fill(tdraw, G19ColorA(0, 0, 0, 0));
-	
-	if(tdraw == NULL)
-		return;
-	
-	for(yy = 0; yy < bitmap -> rows; yy++)
-	{
-		for(xx = 0; xx < bitmap -> width; xx++)
-		{
-			tc = bitmap -> buffer[(yy * bitmap -> width) + xx];
-			
-			if(tc == 0)
-				continue;
-			
-			fcolor = G19ColorA(G19R(fslot -> color), G19G(fslot -> color),
-							  G19B(fslot -> color), (256 + tc));
-			
-			g19_draw_set_pixel(tdraw, fslot -> bitmap_left + xx, (fslot -> height - fslot -> bitmap_top) + yy, fcolor);
-		}
-	}
-	
-	g19_draw_insert_ab(draw, tdraw, x, y, -1);
-	g19_draw_free(tdraw);
-}
-
-#ifdef FT2_SUPPORT
-
-/**
- * Sets the font for drawing
- * 
- * @param ttf_path path to the ttf file
- * @param width width of text
- * @param height height of text
- * @param space space between chars in pixels
- * @param color an unsigned int that hold the color; G19Color() or G19ColorA() can be used
- * 
- * @return non zero on failure
- **/
-int g19_draw_set_font(char * ttf_path, int width, int height, int space, unsigned int color)
-{
-	int res = FT_Init_FreeType(&ft_lib);
-	if(res)
-		return res;
-	
-	res = FT_New_Face(ft_lib, ttf_path, 0, &ft_face);
-	if(res)
-		return res;
-	
-	res = FT_Set_Pixel_Sizes(ft_face, width, height);
-	if(res)
-		return res;
-	
-	ft_width = width;
-	ft_height = height;
-	ft_space = space;
-	ft_color = color;
-	
-	if(space < 0)
-		space = 0;
-	
-	return 0;
-}
-
-/**
- * Draws text on the G19Draw
- * Make sure you have executed g19_draw_set_font
- * 
- * @param draw a pointer G19Draw
- * @param x x coordinate of the upper-left
- * @param y y coordinate of the upper-left
- * @param text pointer to an array of chars to be drawn
- * 
- * @return non zero on failure
- **/
-int g19_draw_text(G19Draw * draw, int x, int y, char * text)
-{
-	int res, i;
-	FT_GlyphSlot slot;
-	FT_UInt gi;
-	
-	if((ft_lib == NULL) || (ft_face == NULL))
-		return -1;
-	
-	slot = ft_face -> glyph;
-	
-	for(i = 0; i < strlen(text); i++)
-	{
-		gi = FT_Get_Char_Index(ft_face, text[i]);
-		
-		if(gi == 0)
-			continue;
-		
-		res = FT_Load_Char(ft_face, (FT_ULong) text[i], FT_LOAD_DEFAULT);
-		if(res)
-			continue;
-		
-		res = FT_Render_Glyph(ft_face -> glyph, FT_RENDER_MODE_NORMAL);
-		if(res)
-			continue;
-		
-		if(slot -> bitmap.width < 1)
-		{
-			x += ft_width;
-			continue;
-		}
-		
-		x += ft_space;
-		
-		G19FontSlot fslot;
-		fslot.width = ft_width;
-		fslot.height = ft_height;
-		fslot.bitmap_left = slot -> bitmap_left;
-		fslot.bitmap_top = slot -> bitmap_top;
-		fslot.color = ft_color;
-		fslot.bitmap = (G19FontBitmap *) &slot -> bitmap;
-		
-		g19_draw_ft_slot(draw, &fslot, x, y);
-		
-		x += slot -> bitmap.width;
-	}
-	
-	return 0;
-}
-
-/**
- * Closes the FreeType library and font handle from g19_draw_set_font()
- **/
-void g19_draw_close_font(void)
-{
-	if(ft_face != NULL)
-		FT_Done_Face(ft_face);
-	
-	if(ft_lib != NULL)
-		FT_Done_FreeType(ft_lib);
-}
-
-#endif
