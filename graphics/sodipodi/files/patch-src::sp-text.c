
$FreeBSD$

--- src/sp-text.c	2001/09/28 13:10:32	1.1
+++ src/sp-text.c	2001/09/28 13:19:21
@@ -235,7 +235,7 @@
 				x = text->x;
 				y += text->size;
 			} else {
-				g_unichar_to_utf8 (btowc(*c), utfbuf);
+				g_unichar_to_utf8 (*c, utfbuf);
 				glyph = gnome_font_face_lookup_default (face, g_utf8_get_char(utfbuf));
 
 				w = gnome_font_face_get_glyph_width (face, glyph);
