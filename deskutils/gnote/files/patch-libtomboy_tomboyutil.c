--- libtomboy/tomboyutil.c.orig	2010-03-14 00:35:24.000000000 -0500
+++ libtomboy/tomboyutil.c	2010-03-14 00:36:19.000000000 -0500
@@ -153,9 +153,9 @@ tomboy_window_override_user_time (GtkWin
 void
 tomboy_window_present_hardcore (GtkWindow *window)
 {
-	if (!GTK_WIDGET_REALIZED (window))
+	if (!gtk_widget_get_realized (window))
 		gtk_widget_realize (GTK_WIDGET (window));
-	else if (GTK_WIDGET_VISIBLE (window))
+	else if (gtk_widget_get_visible (window))
 		tomboy_window_move_to_current_workspace (window);
 
 	tomboy_window_override_user_time (window);
