--- ./src/global.c.orig	2012-12-03 17:33:00.000000000 +0100
+++ ./src/global.c	2012-12-03 17:33:17.000000000 +0100
@@ -730,7 +730,7 @@
 printf("Key1: %04x\n", event->keyval);
 }
 
-gboolean
+void
 main_canvas_keypressed1(GdkEventKey *event)
 {
   GtkWidget *w;
