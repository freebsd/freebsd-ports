--- src/config_dialog.c.orig	Fri Sep 10 17:12:58 2004
+++ src/config_dialog.c	Fri Sep 10 17:16:13 2004
@@ -149,6 +149,7 @@
 	write_config(config);
 	d->saved = 1;
 	gtk_main_quit();
+	gtk_widget_destroy(d->window);
 }
 
 void upload_proto_callback (GtkOptionMenu * menu, gpointer user_data)
@@ -732,7 +733,11 @@
 
 	g_signal_connect ((gpointer) cancel, "clicked",
 		G_CALLBACK (gtk_main_quit), NULL);
-	
+
+	g_signal_connect_swapped ((gpointer) cancel, "clicked",
+		G_CALLBACK (gtk_widget_destroy),
+		(gpointer) (s->window));
+
 	g_signal_connect ((gpointer) save, "clicked",
 			G_CALLBACK (on_config_save_clicked),
 			(gpointer) s);
@@ -757,7 +762,6 @@
 	cd.saved = FALSE;
 
 	gtk_main();
-	gtk_widget_destroy (GTK_WIDGET (opt));
 	return cd.saved;
 }
 
