--- src/gui.c.orig	Mon Jul 26 22:14:52 2004
+++ src/gui.c	Tue Jul 27 00:47:21 2004
@@ -26,6 +26,7 @@
 
 void on_about_activate(GtkMenuItem *menu, Lindele *l)
 {
+    l->about = do_about();
     gtk_widget_show (GTK_WIDGET(l->about));
 }
 
@@ -130,14 +131,14 @@
 
 void on_properties_activate (GtkWidget *menu, Lindele *l)
 {
-    if(g_file_test(g_find_program_in_path("musicbox"),G_FILE_TEST_IS_EXECUTABLE))
+    if(g_file_test(g_find_program_in_path("musicbox-tag-editor"),G_FILE_TEST_IS_EXECUTABLE))
     {
-        g_printf("EXECUTE: %s\n",g_strconcat("musicbox \"",playlist_get_current_filepath(l),"\"",NULL));
-        gnome_execute_shell(NULL,g_strconcat("musicbox \"",playlist_get_current_filepath(l),"\"",NULL));
+        g_printf("EXECUTE: %s\n",g_strconcat("musicbox-tag-editor \"",playlist_get_current_filepath(l),"\"",NULL));
+        gnome_execute_shell(NULL,g_strconcat("musicbox-tag-editor \"",playlist_get_current_filepath(l),"\"",NULL));
     }
     else
     {
-        g_printf("musicbox is not installed on your system\n.");
+        g_printf("musicbox-tag-editor is not installed on your system\n.");
     }
 }
 
@@ -385,13 +386,15 @@
 {
     GtkTreeViewColumn *column;
     GtkCellRenderer *cellrenderer;
+    gchar* gladepath;
     
     l->mmkeys = mmkeys_new();
     l->player = init_player();
-    l->about = do_about();
     l->playlist_num = 0;
+    l->random = FALSE;
+    l->repeat = FALSE;
 
-    gchar* gladepath = g_strconcat(DATADIR,"/lindele/lindele.glade",NULL);
+    gladepath = g_strconcat(DATADIR,"/lindele/lindele.glade",NULL);
 	//gchar* gladepath = g_strconcat("/home/link/Hacking/lindele/lindele-work/data/lindele.glade",NULL);
 	
 	l->xml = glade_xml_new (gladepath, NULL, NULL);
@@ -468,7 +471,7 @@
 	
 	/* Disable the preferences, since its not implemented. */
 	gtk_widget_set_sensitive(GTK_WIDGET(glade_xml_get_widget(l->xml,"m_preferences")),FALSE);
-	if(! g_file_test(g_find_program_in_path("musicbox"),G_FILE_TEST_IS_EXECUTABLE))
+	if(! g_file_test(g_find_program_in_path("musicbox-tag-editor"),G_FILE_TEST_IS_EXECUTABLE))
 	    gtk_widget_set_sensitive(GTK_WIDGET(glade_xml_get_widget(l->xml,"m_properties")),FALSE);
 	
 	update_buttons(l);
