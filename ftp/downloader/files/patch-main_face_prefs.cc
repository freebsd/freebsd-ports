--- main/face/prefs.cc.orig	Wed Nov  6 07:53:28 2002
+++ main/face/prefs.cc	Fri Jun 13 00:50:49 2003
@@ -810,7 +810,7 @@
 	gint i;
 	for (i = 0; (unsigned int)i <count; i++){
 		menu_item = gtk_radio_menu_item_new_with_label (group, labels[i]);
-		group = gtk_radio_menu_item_group (GTK_RADIO_MENU_ITEM (menu_item));
+		group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (menu_item));
 		gtk_menu_shell_append (GTK_MENU_SHELL (menu), menu_item);
 		if (i==TMPCFG.SEARCH_HOST)
 			gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM (menu_item), TRUE);
@@ -1465,9 +1465,10 @@
 		return;
 	};
 	if (equal(label,_("FTP search"))){
+		GSList *group;
 		sscanf(gtk_entry_get_text(GTK_ENTRY(D4XPWS.search_ping_times)),"%u",&TMPCFG.SEARCH_PING_TIMES);
 		sscanf(gtk_entry_get_text(GTK_ENTRY(D4XPWS.search_entries)),"%u",&TMPCFG.SEARCH_ENTRIES);
-		GSList *group=gtk_radio_menu_item_group((GtkRadioMenuItem *)((GtkOptionMenu *)D4XPWS.search_host)->menu_item);
+		group = gtk_radio_menu_item_get_group((GtkRadioMenuItem *)((GtkOptionMenu *)D4XPWS.search_host)->menu_item);
 		int i=D4X_SEARCH_ENGINES.count()-1;
 		if (i<0) i=0;
 		while(group && !((GtkCheckMenuItem *)(group->data))->active){
