2004-04-18 Joe Marcus Clarke <marcus@FreeBSD.org>

* libgnomedb/gnome-db-data-source-selector.c: (show_data_sources):

Be sure to add something to the DSN menu so that this menu gets initialized.
Failure to do so will cause a segmentation fault when trying to login to
the database.

--- libgnomedb/gnome-db-data-source-selector.c.orig	Sun Apr 18 21:41:59 2004
+++ libgnomedb/gnome-db-data-source-selector.c	Sun Apr 18 21:43:20 2004
@@ -61,8 +61,25 @@
 						    dsn_info->name);
 		gnome_db_config_free_data_source_info (dsn_info);
 	}
-	else
+	else {
+		GList *dsn_list;
+		GList *l;
+
+		/* load data sources */
+		dsn_list = gnome_db_config_get_data_source_list ();
+		for (l = dsn_list; l != NULL; l = l->next) {
+			GdaDataSourceInfo *dsn_info = (GdaDataSourceInfo *) l->data;
+
+			if (!dsn_info)
+				continue;
+
+			/* add the data source to the option menu */
+			gnome_db_option_menu_add_item (GTK_OPTION_MENU (selector), dsn_info->name);
+		}
+
+		gnome_db_config_free_data_source_list (dsn_list);
 		gtk_option_menu_set_history (GTK_OPTION_MENU (selector), 0);
+	}
 }
 
 /*
