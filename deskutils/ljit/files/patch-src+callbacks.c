--- src/callbacks.c.orig	Fri Sep 10 17:12:58 2004
+++ src/callbacks.c	Fri Sep 10 17:13:39 2004
@@ -98,6 +98,7 @@
 	g_string_free(html, TRUE);
 
 	gtk_main_quit();
+	gtk_widget_destroy((GtkWidget *) user_data);
 }
 
 
