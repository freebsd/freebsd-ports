--- src/interface.c.orig	Sun Nov 16 22:55:27 2003
+++ src/interface.c	Sun Nov 16 22:57:29 2003
@@ -299,10 +299,12 @@
 		SP_VERB_LAST
 	};
 
+	GtkWidget *item_recent, *menu_recent;
+
 	sp_ui_menu_append (fm, file_verbs_one);
 
- 	GtkWidget *item_recent = sp_ui_menu_append_item (fm, NULL, _("Open Recent"), NULL, NULL);
- 	GtkWidget *menu_recent = gtk_menu_new ();
+ 	item_recent = sp_ui_menu_append_item (fm, NULL, _("Open Recent"), NULL, NULL);
+ 	menu_recent = gtk_menu_new ();
  	sp_menu_append_recent_documents (GTK_WIDGET (menu_recent));
 	gtk_menu_item_set_submenu (GTK_MENU_ITEM (item_recent), menu_recent);
 
@@ -472,11 +474,13 @@
 static void
 sp_ui_populate_main_menu(GtkWidget *m)
 {
+	GtkWidget *item_recent, *menu_recent;
+
 	sp_ui_menu_append_item (GTK_MENU (m), GTK_STOCK_NEW, _("New"), G_CALLBACK(sp_file_new), NULL);
 	sp_ui_menu_append_item (GTK_MENU (m), GTK_STOCK_OPEN, _("Open"), G_CALLBACK(sp_file_open_dialog), NULL);
         
-	GtkWidget *item_recent = sp_ui_menu_append_item (GTK_MENU (m), NULL, _("Open Recent"), NULL, NULL);
-	GtkWidget *menu_recent = gtk_menu_new ();
+	item_recent = sp_ui_menu_append_item (GTK_MENU (m), NULL, _("Open Recent"), NULL, NULL);
+	menu_recent = gtk_menu_new ();
 
 	sp_menu_append_recent_documents (GTK_WIDGET (menu_recent));
 	gtk_menu_item_set_submenu (GTK_MENU_ITEM (item_recent), menu_recent); 
