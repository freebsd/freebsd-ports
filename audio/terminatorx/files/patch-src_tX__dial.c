--- src/tX_dial.c.orig	2011-01-30 21:01:30 UTC
+++ src/tX_dial.c
@@ -266,7 +266,7 @@ static void gtk_tx_dial_size_allocate (G
 	}
 }
 
-inline void gtk_tx_dial_draw (GtkTxDial *tx_dial, GtkWidget *widget)
+static inline void gtk_tx_dial_draw (GtkTxDial *tx_dial, GtkWidget *widget)
 {
 	if (GTK_WIDGET_DRAWABLE (widget)) {
 		gdk_pixbuf_render_to_drawable(knob_pixmaps[tx_dial->old_image], 
