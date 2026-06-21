--- server.c.orig	2026-06-21 21:51:43 UTC
+++ server.c
@@ -64,6 +64,7 @@ static ServerConfig config;
  *  Call init_font() to set up the CHAR_X and CHAR_Y tables, then
  *  draw_string() to put text on the xpm.
  */
+#undef CHAR_WIDTH
 static const int CHAR_WIDTH = 6;
 static const int CHAR_HEIGHT = 7;
 
