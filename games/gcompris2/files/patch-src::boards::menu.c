--- src/boards/menu.c.orig	Wed Apr 23 21:38:22 2003
+++ src/boards/menu.c	Wed Apr 23 21:39:20 2003
@@ -153,6 +153,7 @@
       gcomprisBoard->maxlevel=1;
       gcompris_bar_set(GCOMPRIS_BAR_CONFIG|GCOMPRIS_BAR_ABOUT);
 
+      gnome_canvas_update_now(gcomprisBoard->canvas);
       menu_pause(FALSE);
 
     }
