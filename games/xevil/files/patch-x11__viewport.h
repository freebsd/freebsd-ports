--- x11/viewport.h.orig	2012-05-27 06:52:31.000000000 +0900
+++ x11/viewport.h	2012-05-27 06:52:59.000000000 +0900
@@ -348,7 +348,7 @@
   /* NOTE: Will draw everything if redrawArena is true, else just what has
      changed. */
 
-  void draw_string(const Pos &pos,char *msg);
+  void draw_string(const Pos &pos,const char *msg);
   /* EFFECTS: Draw string msg using current GC on arena with upper left of
      character at position pos. */
 
