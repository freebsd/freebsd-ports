--- src/gui.c.orig	Tue Jan 18 02:32:02 2005
+++ src/gui.c	Tue Jan 18 02:32:04 2005
@@ -303,7 +303,6 @@
 
 gboolean on_tree_popup_menu (GtkWidget *widget)
 {
-    g_printf("got popup-menu signal\n");
     popup_context_menu(widget,NULL);
     return TRUE;
 }
