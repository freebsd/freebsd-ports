--- libgnomecanvas/gnome-canvas-shape.c.orig	Fri May 20 16:55:35 2005
+++ libgnomecanvas/gnome-canvas-shape.c	Fri May 20 16:55:41 2005
@@ -1343,7 +1343,7 @@ gcbp_destroy_gdk (GnomeCanvasShape * sha
 {
 	GnomeCanvasShapePrivGdk * gdk;
 
-	g_assert (!((GnomeCanvasItem *)shape)->canvas->aa);
+	/*g_assert (!((GnomeCanvasItem *)shape)->canvas->aa);*/
 
 	gdk = shape->priv->gdk;
 
