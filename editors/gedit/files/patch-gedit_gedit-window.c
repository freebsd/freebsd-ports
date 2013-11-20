--- gedit/gedit-window.c	2011-03-05 23:07:51.000000000 +0000
+++ gedit/gedit-window.c	2011-02-03 10:10:22.000000000 +0000
@@ -1685,9 +1685,6 @@
 			    0);
 
 	window->priv->toolbar = gtk_ui_manager_get_widget (manager, "/ToolBar");
-	gtk_style_context_add_class (gtk_widget_get_style_context (window->priv->toolbar),
-				     GTK_STYLE_CLASS_PRIMARY_TOOLBAR);
-
 	gtk_box_pack_start (GTK_BOX (main_box),
 			    window->priv->toolbar,
 			    FALSE,
