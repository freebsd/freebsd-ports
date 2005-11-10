
$FreeBSD$

--- libgnomedb/gnome-db-grid.c.orig
+++ libgnomedb/gnome-db-grid.c
@@ -1917,6 +1917,7 @@
 	else {
 		/* render all the parameters invalid */
 		grid->priv->internal_params_change = TRUE;
+		{
 		GSList *list = grid->priv->data_set->parameters;
 		while (list) {
 			GnomeDbParameter *tmp;
@@ -1925,6 +1926,7 @@
 				gnome_db_parameter_declare_invalid (GNOME_DB_PARAMETER (list->data));
 			
 			list = g_slist_next (list);
+		}
 		}
 		grid->priv->internal_params_change = FALSE;
 	}
