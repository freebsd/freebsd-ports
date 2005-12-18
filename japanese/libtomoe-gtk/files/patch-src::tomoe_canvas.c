Index: src/tomoe_canvas.c
diff -u -p src/tomoe_canvas.c.orig src/tomoe_canvas.c
--- src/tomoe_canvas.c.orig	Tue Oct 18 17:56:15 2005
+++ src/tomoe_canvas.c	Mon Dec 19 03:53:30 2005
@@ -1073,9 +1073,11 @@ draw_stroke (GList *stroke, TomoeCanvas 
     
     for (node = stroke; node; node = g_list_next (node)) {
         GList *next = g_list_next (node);
+        point *p1, *p2;
         if (!next) break;
 
-        point *p1 = (point*) node->data, *p2 = (point*) next->data;
+        p1 = (point*) node->data;
+        p2 = (point*) next->data;
         tomoe_canvas_draw_line (canvas, p1, p2, FALSE);
     }
     draw_annotate (stroke, canvas, *index);
