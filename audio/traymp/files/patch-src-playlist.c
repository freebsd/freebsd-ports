--- src/playlist.c.orig	Thu Aug 28 17:46:31 2003
+++ src/playlist.c	Mon Nov 17 19:08:53 2003
@@ -41,9 +41,9 @@
 void switch_advanced()
     {
 	int height;
+   GtkRequisition requisition;
 	gtk_window_get_size(GTK_WINDOW(glade_xml_get_widget(xml, "playlist_win")), NULL, &height);
 
-   GtkRequisition requisition;
 	gtk_widget_get_child_requisition
                                             (glade_xml_get_widget(xml, "vbox1"),
                                              &requisition);
@@ -368,10 +368,12 @@
     {
 	GtkTreeIter iter;
 	GtkTreeModel *model = GTK_TREE_MODEL(playlists);
+	GtkWidget *entry;
+	const gchar *buf;
 	if(!insetting.update_timeout) return;
 	insetting.update_timeout = FALSE;
-    GtkWidget *entry = glade_xml_get_widget(xml, "playlist_name");    
-    const gchar *buf = gtk_entry_get_text(GTK_ENTRY(entry));
+    entry = glade_xml_get_widget(xml, "playlist_name");    
+    buf = gtk_entry_get_text(GTK_ENTRY(entry));
     if(strlen(buf) == 0) return;
 	if(gtk_tree_model_get_iter_first(model, &iter))
 		{
@@ -413,12 +415,14 @@
 /** remove's the selected playlist */
 void delete_playlist()
     {
-	if(!insetting.update_timeout) return;
-	insetting.update_timeout = FALSE;
     GtkTreeSelection *selection;
     GtkTreeIter iter;
-    GtkWidget *tree = glade_xml_get_widget(xml, "tree_playlists");
-    GtkTreeModel *model = GTK_TREE_MODEL(playlists);
+    GtkWidget *tree;
+    GtkTreeModel *model;
+	if(!insetting.update_timeout) return;
+	insetting.update_timeout = FALSE;
+    tree = glade_xml_get_widget(xml, "tree_playlists");
+    model = GTK_TREE_MODEL(playlists);
     selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(tree));
     if(gtk_tree_selection_get_selected(selection, &model, &iter))
 	{
@@ -474,12 +478,14 @@
 void search_songs()
 	{
 	mpd_InfoEntity *entity;
-	gtk_list_store_clear(searchlist);
 	GtkWidget *entry;
-	GtkWidget *progress = start_progress("Loading search results");
+	GtkWidget *progress;
 	int i=0, option =0;
+	const gchar *entryb;
+	gtk_list_store_clear(searchlist);
+	progress = start_progress("Loading search results");
 	entry = glade_xml_get_widget(xml, "search_entry");
-	const gchar *entryb = gtk_entry_get_text(GTK_ENTRY(entry));
+	entryb = gtk_entry_get_text(GTK_ENTRY(entry));
 	if(gtk_option_menu_get_history(GTK_OPTION_MENU(glade_xml_get_widget(xml, "search_type_selector"))) == 0) option = MPD_TABLE_ARTIST;
 	else if (gtk_option_menu_get_history(GTK_OPTION_MENU(glade_xml_get_widget(xml, "search_type_selector"))) == 1) option = MPD_TABLE_ALBUM;
 	else if (gtk_option_menu_get_history(GTK_OPTION_MENU(glade_xml_get_widget(xml, "search_type_selector"))) == 2) option = MPD_TABLE_TITLE;
@@ -491,8 +497,9 @@
 	while((entity = mpd_getNextInfoEntity(connection)))
 			{
 			GtkTreeIter iter;
+			char *buf;
 	check_error();
-			char *buf = g_path_get_basename(entity->info.song->file);
+			buf = g_path_get_basename(entity->info.song->file);
 			if(!(i % 50))
 				{
 				gtk_progress_bar_pulse(GTK_PROGRESS_BAR(progress));
@@ -640,12 +647,15 @@
 void load_albums()
     {
 	char *buf, *artist;
-	gtk_list_store_clear(id3_album);
 	GtkTreeIter iter;
-	GtkTreeModel *model = GTK_TREE_MODEL(id3_artist);
-	GtkTreeSelection *selection = gtk_tree_view_get_selection((GtkTreeView *)glade_xml_get_widget(xml, "tree_artist"));
-	GtkWidget *progress = start_progress("Loading albums");
+	GtkTreeModel *model;
+	GtkTreeSelection *selection;
+	GtkWidget *progress;
 	int i =0;
+	gtk_list_store_clear(id3_album);
+	model = GTK_TREE_MODEL(id3_artist);
+	selection = gtk_tree_view_get_selection((GtkTreeView *)glade_xml_get_widget(xml, "tree_artist"));
+	progress = start_progress("Loading albums");
 	if(!gtk_tree_selection_get_selected(selection, &model, &iter)) return;
 	else gtk_tree_model_get(model , &iter, 0,&artist,-1);
 	if(!strcmp(artist, "All")) mpd_sendListCommand(connection, MPD_TABLE_ALBUM, NULL);
@@ -1092,11 +1102,14 @@
 	mpd_InfoEntity *entity;
 	gchar *entryb,*buf = NULL;
 	GPatternSpec *spec;
-	gtk_list_store_clear(curlist);
-	GtkWidget *progress= start_progress("Loading songs in current playlist");
-	int option = gtk_option_menu_get_history(GTK_OPTION_MENU(glade_xml_get_widget(xml, "optionmenufilter")));
-	GtkWidget *entry = glade_xml_get_widget(xml, "entryfilter");
+	GtkWidget *progress;
+	int option;
+	GtkWidget *entry;
 	int i=0, rate = 50;
+	gtk_list_store_clear(curlist);
+	progress= start_progress("Loading songs in current playlist");
+	option = gtk_option_menu_get_history(GTK_OPTION_MENU(glade_xml_get_widget(xml, "optionmenufilter")));
+	entry = glade_xml_get_widget(xml, "entryfilter");
 	/* if there is a playlistlength set the update rate to every 2.5 % */
 	if(status->playlistLength != -1) rate = (int)(status->playlistLength/40 + 1);
 	/* this is needed to get the right number of songs in the playlist */
