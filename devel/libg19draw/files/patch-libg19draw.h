--- libg19draw.h.orig	2010-04-11 04:51:51.000000000 +0200
+++ libg19draw.h	2011-04-16 08:26:10.000000000 +0200
@@ -19,12 +19,26 @@
 #ifndef LIBG19DRAW_H
 #define LIBG19DRAW_H
 
+#include <string.h>
+
+#ifdef FT2_SUPPORT
+
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#include FT_BITMAP_H
+
+#endif
+
 #ifdef __cplusplus
 extern "C"
 {
 #endif
 
-#define LIBG19DRAW_VERSION "1.0.0"
+#define LIBG19DRAW_VERSION_MAJOR	1
+#define LIBG19DRAW_VERSION_MINOR	1
+#define LIBG19DRAW_VERSION_MICRO	0
+
+#define LIBG19DRAW_VERSION			"1.1.0"
 
 #define G19_WIDTH		320
 #define G19_HEIGHT		240
@@ -44,30 +58,25 @@
 {
 	int width;
 	int height;
-	int size;
+	size_t size;
 	unsigned char * data;
 }
 G19Draw;
 
-typedef struct
-{
-	int rows;
-	int width;
-	int pitch;
-	unsigned char * buffer;
-}
-G19FontBitmap;
+#ifdef FT2_SUPPORT
 
 typedef struct
 {
+	FT_Library lib;
+	FT_Face face;
 	int width;
 	int height;
-	int bitmap_left;
-	int bitmap_top;
+	int space;
 	unsigned int color;
-	G19FontBitmap * bitmap;
 }
-G19FontSlot;
+G19Font;
+
+#endif
 
 /**
  * Creates a new G19Draw
@@ -99,6 +108,28 @@
 void g19_draw_free(G19Draw * draw);
 
 /**
+ * Save a G19Draw to an 24-bit bitmap
+ * 
+ * @param draw pointer to a G19Draw
+ * @param path path to save the image to
+ * 
+ * @return 0 on success; non-zero on error
+ **/
+int g19_draw_to_bmp(G19Draw * draw, char * path);
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
+G19Draw * g19_draw_resize(G19Draw * draw, int width, int height, unsigned int color, int free_old);
+
+/**
  * Insert a G19Draw onto another G19Draw
  * 
  * @param draw pointer to the destination G19Draw
@@ -185,18 +216,11 @@
  **/
 void g19_draw_circle(G19Draw * draw, int cx, int cy, int cr, int fill, unsigned int color);
 
-/**
- * Draws a slot from FreeType on the G19Draw
- * 
- * @param draw a pointer G19Draw
- * @param fslot G19FontSlot that holds the FreeType slot data
- **/
-void g19_draw_ft_slot(G19Draw * draw, G19FontSlot * fslot, int x, int y);
 
 #ifdef FT2_SUPPORT
 
 /**
- * Sets the font for drawing
+ * Creates a new G19Font
  * 
  * @param ttf_path path to the ttf file
  * @param width width of text
@@ -204,27 +228,55 @@
  * @param space space between chars in pixels
  * @param color an unsigned int that hold the color; G19Color() or G19ColorA() can be used
  * 
- * @return non zero on failure
+ * @return pointer to a G19Font or NULL on error
+ **/
+G19Font * g19_font_new(char * ttf_path, int width, int height, int space, unsigned int color);
+
+/**
+ * Sets the character size on the G19Font
+ * 
+ * @param font a pointer G19Font
+ * @param width width of text
+ * @param height height of text
+ **/
+void g19_font_set_size(G19Font * font, int width, int height);
+
+/**
+ * Sets the character spacing on the G19Font
+ * 
+ * @param font a pointer G19Font
+ * @param space between characters in pixels
  **/
-int g19_draw_set_font(char * ttf_path, int width, int height, int space, unsigned int color);
+void g19_font_set_space(G19Font * font, int space);
 
 /**
- * Draws text on the G19Draw
- * Make sure you have executed g19_draw_set_font
+ * Sets the color on the G19Font
  * 
+ * @param font a pointer G19Font
+ * @param color the color to set the text; G19Color() or G19ColorA() can be used
+ **/
+void g19_font_set_color(G19Font * font, unsigned int color);
+
+/**
+ * Draws text on the G19Draw with G19Font
+ * 
+ * @param font a pointer G19Font
  * @param draw a pointer G19Draw
  * @param x x coordinate of the upper-left
  * @param y y coordinate of the upper-left
  * @param text pointer to an array of chars to be drawn
  * 
- * @return non zero on failure
+ * @return the number of characters written or < 0 on error
  **/
-int g19_draw_text(G19Draw * draw, int x, int y, char * text);
+int g19_font_draw(G19Font * font, G19Draw * draw, int x, int y, char * text);
+
 
 /**
- * Closes the FreeType library and font handle from g19_draw_set_font()
+ * Frees a G19Font
+ * 
+ * @param font a pointer G19Font
  **/
-void g19_draw_close_font(void);
+void g19_font_free(G19Font * font);
 
 #endif
 
