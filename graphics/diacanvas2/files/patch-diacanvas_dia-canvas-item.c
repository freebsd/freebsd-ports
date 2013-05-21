--- diacanvas/dia-canvas-item.c.orig	2013-05-21 08:53:38.000000000 +0000
+++ diacanvas/dia-canvas-item.c	2013-05-21 08:55:27.000000000 +0000
@@ -709,7 +709,7 @@ dia_real_canvas_item_disconnect (DiaCanv
 
 static void item_button_press_event(DiaCanvasItem *item, gpointer event)
        {
-        return TRUE;
+        return;
        }
 
 /**
