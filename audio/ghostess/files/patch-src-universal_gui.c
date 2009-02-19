--- src/universal_gui.c.orig	2009-01-11 15:40:04.000000000 +0100
+++ src/universal_gui.c	2009-01-11 15:42:28.000000000 +0100
@@ -610,8 +610,9 @@
                                             (gpointer)port);
 
         /* update bounds */
-        gtk_adjustment_set_lower(GTK_ADJUSTMENT(port_data[port].adjustment), plb);
-        gtk_adjustment_set_upper(GTK_ADJUSTMENT(port_data[port].adjustment), pub);
+        GTK_ADJUSTMENT(port_data[port].adjustment)->lower = plb;
+        GTK_ADJUSTMENT(port_data[port].adjustment)->upper = pub;
+        gtk_adjustment_changed(GTK_ADJUSTMENT(port_data[port].adjustment));
 
         /* update labels */
         if (port_data[port].bounded) {
