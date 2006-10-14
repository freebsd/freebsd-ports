--- plugins/font/server/freefnt2/freefnt2.cpp.orig	Thu Oct 12 12:48:44 2006
+++ plugins/font/server/freefnt2/freefnt2.cpp	Thu Oct 12 12:54:51 2006
@@ -30,10 +30,11 @@
 #include "iutil/comp.h"
 
 #include <ft2build.h>
-#include FT_INTERNAL_OBJECTS_H
 #include FT_FREETYPE_H
 #include FT_GLYPH_H
 #include FT_MODULE_H
+#include FT_SIZES_H
+#include FT_OUTLINE_H
 
 #include "freefnt2.h"
 
@@ -372,6 +373,20 @@
   return true;
 }
 
+static void GridFitCbox (FT_BBox& cbox, FT_UInt& glyphW, FT_UInt& glyphH)
+{
+  /* compute the control box, and grid fit it */
+#define FT_PIX_FLOOR( x )     ( (x) & ~63 )
+#define FT_PIX_CEIL( x )      FT_PIX_FLOOR( (x) + 63 )
+  cbox.xMin = FT_PIX_FLOOR( cbox.xMin );
+  cbox.yMin = FT_PIX_FLOOR( cbox.yMin );
+  cbox.xMax = FT_PIX_CEIL( cbox.xMax );
+  cbox.yMax = FT_PIX_CEIL( cbox.yMax );
+
+  glyphW = (FT_UInt)( ( cbox.xMax - cbox.xMin ) >> 6 );
+  glyphH = (FT_UInt)( ( cbox.yMax - cbox.yMin ) >> 6 );
+}
+
 csPtr<iDataBuffer> csFreeType2Font::GetGlyphBitmap (utf32_char c,
 						    csBitmapMetrics& metrics)
 {
@@ -381,37 +396,65 @@
   if ((c != CS_FONT_DEFAULT_GLYPH) && (ci == 0)) return 0;
 
   if (server->FreetypeError (FT_Load_Glyph (face->face, ci, 
-    FT_LOAD_RENDER | FT_LOAD_MONOCHROME | FT_LOAD_TARGET_MONO),
+    FT_LOAD_MONOCHROME | FT_LOAD_TARGET_MONO),
     "Could not load glyph %u for %s", ci, name))
   {
     return 0;
   }
 
-  int stride = (face->face->glyph->bitmap.width + 7) / 8;
+  /* Work around an FT2.2.1 issue where rendering of a glyph fails if the width
+   * or height is 0 */
+  FT_Outline* outline = &face->face->glyph->outline;
+  FT_BBox cbox;
+  FT_Outline_Get_CBox( outline, &cbox );
+  FT_UInt glyphW, glyphH;
+  GridFitCbox (cbox, glyphW, glyphH);
   int maxrows = (size->metrics.height + 63) >> 6;
-  int bitmapsize = maxrows*stride;
-  uint8* bitmap = new uint8 [bitmapsize];
-  memset (bitmap, 0, bitmapsize);
+  int stride, bitmapsize;
+  uint8* bitmap;
+  if ((glyphW > 0) && (glyphH > 0))
+  {
+    if (server->FreetypeError (FT_Render_Glyph (face->face->glyph, 
+      FT_RENDER_MODE_MONO),
+      "Could not render glyph %u for %s", ci, name))
+    {
+      return 0;
+    }
+    stride = (face->face->glyph->bitmap.width + 7) / 8;
+    bitmapsize = maxrows*stride;
+  }
+  else
+    bitmapsize = 0;
 
   int descend = (-size->metrics.descender + 63) >> 6;;
 
-  int startrow = maxrows - (descend + face->face->glyph->bitmap_top);
-
-  int endrow = startrow + face->face->glyph->bitmap.rows;
+  if (bitmapsize > 0)
+  {
+    int startrow = maxrows - (descend + face->face->glyph->bitmap_top);
+    int endrow = startrow + face->face->glyph->bitmap.rows;
 
-  if (startrow < 0) startrow = 0;
-  if (endrow > maxrows) endrow = maxrows;
+    if (startrow < 0) startrow = 0;
+    if (endrow > maxrows) endrow = maxrows;
 
-  int n, i;
-  for (n = 0, i = startrow; i < endrow; i++, n++)
-    memcpy (bitmap + stride*i, 
-            face->face->glyph->bitmap.buffer + 
-	    n * face->face->glyph->bitmap.pitch,
-            MIN(stride, face->face->glyph->bitmap.pitch));
+    bitmap = new uint8 [bitmapsize];
+    memset (bitmap, 0, bitmapsize);
+    int n, i;
+    for (n = 0, i = startrow; i < endrow; i++, n++)
+      memcpy (bitmap + stride*i, 
+              face->face->glyph->bitmap.buffer + 
+	      n * face->face->glyph->bitmap.pitch,
+              MIN(stride, face->face->glyph->bitmap.pitch));
+    metrics.width = face->face->glyph->bitmap.width;
+    metrics.left = face->face->glyph->bitmap_left;
+  }
+  else
+  {
+    bitmap = 0;
+    metrics.width = glyphW >> 6;
+    metrics.left = (FT_Int)( cbox.xMin >> 6 );
+  }
 
-  metrics.width = face->face->glyph->bitmap.width;
   metrics.height = maxrows;
-  metrics.left = face->face->glyph->bitmap_left;
   metrics.top = maxrows - descend;
 
   return (csPtr<iDataBuffer> (new csDataBuffer ((char*)bitmap, bitmapsize, 
@@ -427,42 +470,70 @@
   if ((c != CS_FONT_DEFAULT_GLYPH) && (ci == 0)) return 0;
 
   if (server->FreetypeError (FT_Load_Glyph (face->face, ci, 
-    FT_LOAD_RENDER | FT_RENDER_MODE_NORMAL),
+    FT_LOAD_TARGET_NORMAL),
     "Could not load glyph %u for %s", ci, name))
   {
     return 0;
   }
 
-  if (face->face->glyph->bitmap.pixel_mode != FT_PIXEL_MODE_GRAY)
-    // That's not what we want.
-    return 0;
-
-  int stride = face->face->glyph->bitmap.width;
+  /* Work around an FT2.2.1 issue where rendering of a glyph fails if the width
+   * or height is 0 */
+  FT_Outline* outline = &face->face->glyph->outline;
+  FT_BBox cbox;
+  FT_Outline_Get_CBox( outline, &cbox );
+  FT_UInt glyphW, glyphH;
+  GridFitCbox (cbox, glyphW, glyphH);
   int maxrows = (size->metrics.height + 63) >> 6;
-  int bitmapsize = maxrows * stride;
-  // Allocate at least 1 byte
-  uint8* bitmap = (bitmapsize > 0) ? new uint8 [bitmapsize] : new uint8[1];
-  memset (bitmap, 0, bitmapsize);
+  int stride, bitmapsize;
+  uint8* bitmap;
+  if ((glyphW > 0) && (glyphH > 0))
+  {
+    if (server->FreetypeError (FT_Render_Glyph (face->face->glyph, 
+      FT_RENDER_MODE_NORMAL),
+      "Could not render glyph %u for %s", ci, name))
+    {
+      return 0;
+    }
+    if (face->face->glyph->bitmap.pixel_mode != FT_PIXEL_MODE_GRAY)
+    {
+      // That's not what we want.
+      return 0;
+    }
+    stride = face->face->glyph->bitmap.width;
+    bitmapsize = maxrows*stride;
+    metrics.width = face->face->glyph->bitmap.width;
+    metrics.left = face->face->glyph->bitmap_left;
+  }
+  else
+  {
+    bitmapsize = 0;
+    metrics.width = glyphW >> 6;
+    metrics.left = (FT_Int)( cbox.xMin >> 6 );
+  }
 
   int descend = (-size->metrics.descender + 63) >> 6;
 
-  int startrow = maxrows - (descend + face->face->glyph->bitmap_top);
-
-  int endrow = startrow + face->face->glyph->bitmap.rows;
+  if (bitmapsize > 0)
+  {
+    int startrow = maxrows - (descend + face->face->glyph->bitmap_top);
+    int endrow = startrow + face->face->glyph->bitmap.rows;
 
-  if (startrow < 0) startrow = 0;
-  if (endrow > maxrows) endrow = maxrows;
+    if (startrow < 0) startrow = 0;
+    if (endrow > maxrows) endrow = maxrows;
 
-  int n, i;
-  for (n = 0, i = startrow; i < endrow; i++, n++)
-    memcpy (bitmap + stride*i, 
-            face->face->glyph->bitmap.buffer + 
-	    n * face->face->glyph->bitmap.pitch,
-            MIN(stride, face->face->glyph->bitmap.pitch));
+    bitmap = new uint8 [bitmapsize];
+    memset (bitmap, 0, bitmapsize);
+    int n, i;
+    for (n = 0, i = startrow; i < endrow; i++, n++)
+      memcpy (bitmap + stride*i, 
+              face->face->glyph->bitmap.buffer + 
+	      n * face->face->glyph->bitmap.pitch,
+              MIN(stride, face->face->glyph->bitmap.pitch));
+  }
+  else
+    bitmap = 0;
 
-  metrics.width = face->face->glyph->bitmap.width;
   metrics.height = maxrows;
-  metrics.left = face->face->glyph->bitmap_left;
   metrics.top = maxrows - descend;
 
   return (csPtr<iDataBuffer> (new csDataBuffer ((char*)bitmap, bitmapsize, 
