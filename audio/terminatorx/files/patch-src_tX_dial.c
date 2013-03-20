--- src/tX_dial.c.orig	2013-03-20 09:38:30.000000000 +0100
+++ src/tX_dial.c	2013-03-20 09:38:43.000000000 +0100
@@ -266,7 +266,7 @@
 	}
 }
 
-inline void gtk_tx_dial_draw (GtkTxDial *tx_dial, GtkWidget *widget)
+static inline void gtk_tx_dial_draw (GtkTxDial *tx_dial, GtkWidget *widget)
 {
 	if (GTK_WIDGET_DRAWABLE (widget)) {
 		gdk_pixbuf_render_to_drawable(knob_pixmaps[tx_dial->old_image], 
