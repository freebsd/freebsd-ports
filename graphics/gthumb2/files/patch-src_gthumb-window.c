--- src/gthumb-window.c.orig	Tue Nov 12 15:06:10 2002
+++ src/gthumb-window.c	Tue Nov 12 15:06:26 2002
@@ -5162,7 +5162,7 @@
 
 	bonobo_window_set_contents (BONOBO_WINDOW (window->app), paned1);
 
-	gtk_widget_destroy (window->main_pane);
+	window->main_pane = NULL;
 
 	gtk_widget_show (paned1);
 	gtk_widget_show (paned2);
