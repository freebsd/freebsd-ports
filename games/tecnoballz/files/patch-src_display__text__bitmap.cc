--- src/display_text_bitmap.cc.orig	2026-06-25 07:44:17 UTC
+++ src/display_text_bitmap.cc
@@ -108,7 +108,7 @@ display_text_bitmap::load_bitmap_fonts (Uint32 resourc
   off_desti1 = game_screen->get_row_size ();    //modulo destination
   off_source = bitmap_fonts->get_row_size ();     //modulo source
   
-  char_width = CHAR_WIDTH * resolution;
+  char_width = 8 * resolution;
   char_height = bitmap_fonts->get_height ();
 
   rect_fonts.y = 0; 
