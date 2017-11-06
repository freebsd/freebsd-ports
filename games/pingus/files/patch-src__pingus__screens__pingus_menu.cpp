--- src/pingus/screens/pingus_menu.cpp.orig	2011-12-24 21:46:47 UTC
+++ src/pingus/screens/pingus_menu.cpp
@@ -153,7 +153,7 @@ PingusMenu::draw_background(DrawingConte
                          gc.get_height()/2 - 280));
 
   gc.print_left(Fonts::pingus_small, Vector2i(gc.get_width()/2 - 400 + 25, gc.get_height()-140),
-                "Pingus "VERSION" - Copyright (C) 1998-2011 Ingo Ruhnke <grumbel@gmail.com>\n"
+                "Pingus " VERSION " - Copyright (C) 1998-2011 Ingo Ruhnke <grumbel@gmail.com>\n"
                 "See the file AUTHORS for a complete list of contributors.\n"
                 "Pingus comes with ABSOLUTELY NO WARRANTY. This is free software, and you are\n"
                 "welcome to redistribute it under certain conditions; see the file COPYING for details.\n");
