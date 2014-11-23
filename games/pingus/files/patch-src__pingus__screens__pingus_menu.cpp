--- src/pingus/screens/pingus_menu.cpp.orig	2011-12-25 01:46:47.000000000 +0400
+++ src/pingus/screens/pingus_menu.cpp	2014-10-17 23:58:35.000000000 +0400
@@ -153,7 +153,7 @@
                          gc.get_height()/2 - 280));
 
   gc.print_left(Fonts::pingus_small, Vector2i(gc.get_width()/2 - 400 + 25, gc.get_height()-140),
-                "Pingus "VERSION" - Copyright (C) 1998-2011 Ingo Ruhnke <grumbel@gmail.com>\n"
+                "Pingus " VERSION " - Copyright (C) 1998-2011 Ingo Ruhnke <grumbel@gmail.com>\n"
                 "See the file AUTHORS for a complete list of contributors.\n"
                 "Pingus comes with ABSOLUTELY NO WARRANTY. This is free software, and you are\n"
                 "welcome to redistribute it under certain conditions; see the file COPYING for details.\n");
