--- src/interface.c.orig	Fri Sep 10 17:12:58 2004
+++ src/interface.c	Fri Sep 10 17:17:45 2004
@@ -215,8 +215,12 @@
 			G_CALLBACK (on_button_config_clicked), NULL);
 	g_signal_connect ((gpointer) button1, "clicked",
 			G_CALLBACK (gtk_main_quit), NULL);
+	g_signal_connect_swapped ((gpointer) button1, "clicked",
+			G_CALLBACK (gtk_widget_destroy),
+			(gpointer) win->window);
 	g_signal_connect ((gpointer) win->button_ok, "clicked",
-			G_CALLBACK (on_button_ok_clicked), NULL);
+			G_CALLBACK (on_button_ok_clicked),
+			(gpointer) win->window);
 	g_signal_connect ((gpointer) is->slider, "value_changed",
 			G_CALLBACK (tscale_callback), (gpointer) ts);
 
