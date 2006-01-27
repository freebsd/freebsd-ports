--- client/gtk/settingscreen.c.orig	Fri Jan 27 07:22:40 2006
+++ client/gtk/settingscreen.c	Fri Jan 27 07:22:56 2006
@@ -298,9 +298,10 @@
 	if (settings_dlg) {
 		GtkWidget *vbox;
 		GtkWidget *dlg_vbox;
+		GList *list;
 
 		dlg_vbox = GTK_DIALOG(settings_dlg)->vbox;
-		GList *list =
+		list =
 		    gtk_container_get_children(GTK_CONTAINER(dlg_vbox));
 
 		if (g_list_length(list) > 0)
