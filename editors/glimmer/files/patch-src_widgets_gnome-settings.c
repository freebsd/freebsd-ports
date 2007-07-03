--- src/widgets/gnome-settings.c.orig	Tue Jul  3 15:45:49 2007
+++ src/widgets/gnome-settings.c	Tue Jul  3 15:46:49 2007
@@ -138,7 +138,7 @@ select_event (GtkCTree * tree, gint row,
         gtk_widget_hide (settings->current);
     if (data) {
         gtk_widget_show (GTK_WIDGET (data));
-        (void *) settings->current = data;
+        settings->current = GTK_WIDGET (data);
     }
 }
 
