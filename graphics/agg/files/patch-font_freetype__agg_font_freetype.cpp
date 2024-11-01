--- font_freetype/agg_font_freetype.cpp.orig	2023-08-21 15:51:12 UTC
+++ font_freetype/agg_font_freetype.cpp
@@ -158,7 +158,7 @@ namespace agg
 
         FT_Vector*  point;
         FT_Vector*  limit;
-        char*       tags;
+        unsigned char *tags;
 
         int   n;         // index of contour in outline
         int   first;     // index of first point in contour
