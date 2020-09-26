--- src/menu.c.orig	2011-05-04 00:15:06 UTC
+++ src/menu.c
@@ -79,7 +79,7 @@ static char* activities[] = { ACTIVITIES };
 //const int min_font_size = 8, default_font_size = 20, max_font_size = 33;
 
 /* menu title rect */
-SDL_Rect menu_title_rect;
+extern SDL_Rect menu_title_rect;
 
 /* buffer size used when reading attributes or names */
 const int buf_size = 128;
