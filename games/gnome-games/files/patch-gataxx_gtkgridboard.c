--- gataxx/gtkgridboard.c.orig	Thu May 20 17:17:56 2004
+++ gataxx/gtkgridboard.c	Thu May 20 17:18:13 2004
@@ -140,6 +140,7 @@
 static gint gtk_gridboard_button_press(GtkWidget *widget, GdkEventButton *event)
  {
         GtkGridBoard * gridboard;
+	int x, y;
         
         g_return_val_if_fail (widget != NULL, FALSE);
         g_return_val_if_fail (GTK_IS_GRIDBOARD(widget), FALSE);
@@ -147,8 +148,8 @@
 
         gridboard=GTK_GRIDBOARD(widget);
         
-        int x=event->x/gridboard->tilewidth;
-        int y=event->y/gridboard->tileheight;
+        x=event->x/gridboard->tilewidth;
+        y=event->y/gridboard->tileheight;
         g_signal_emit (G_OBJECT(widget), 
                 gridboard_signals[BOXCLICKED], 0, x, y);
         return TRUE;
