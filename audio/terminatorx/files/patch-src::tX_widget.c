--- src/tX_widget.c.orig	Sat Apr 19 13:56:36 2003
+++ src/tX_widget.c	Sat Apr 19 14:13:50 2003
@@ -154,10 +154,10 @@
 }
 
 static void gtk_tx_destroy(GtkObject * object) {
+	GtkTx *tx=GTK_TX(object);
+
 	g_return_if_fail(object != NULL);
 	g_return_if_fail(GTK_IS_TX(object));
-
-	GtkTx *tx=GTK_TX(object);
 	
 	if (tx->disp_data) { free(tx->disp_data); tx->disp_data=NULL; }
 	
