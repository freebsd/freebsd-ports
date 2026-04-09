--- libgda-ui/gdaui-raw-grid.c.orig	2020-11-08 20:23:19 UTC
+++ libgda-ui/gdaui-raw-grid.c
@@ -517,7 +517,7 @@ gdaui_raw_grid_set_property (GObject *object,
 			if (!grid->priv->proxy) {
 				/* first time setting */
 				if (GDA_IS_DATA_PROXY (model))
-					grid->priv->proxy = g_object_ref (G_OBJECT (model));
+					grid->priv->proxy = (GdaDataProxy *) g_object_ref (G_OBJECT (model));
 				else
 					grid->priv->proxy = GDA_DATA_PROXY (gda_data_proxy_new (model));
 
@@ -787,7 +787,7 @@ create_columns_data (GdauiRawGrid *grid)
 			/* FIXME: if nullok is FALSE, then set the column title in bold */
 			cdata->tooltip_text = g_strdup (_("Can't be NULL"));
 			renderer = gdaui_data_cell_renderer_combo_new (grid->priv->iter_info, gdaui_set_group_get_source (group));
-			cdata->data_cell = g_object_ref_sink ((GObject*) renderer);
+			cdata->data_cell = (GtkCellRenderer *) g_object_ref_sink ((GObject*) renderer);
 			g_hash_table_insert (grid->priv->columns_hash, renderer, cdata);
 			g_free (cdata->title);
 			cdata->title = title;
@@ -827,7 +827,7 @@ create_columns_data (GdauiRawGrid *grid)
 						   GDAUI_ATTRIBUTE_PLUGIN);
 			}
 			renderer = _gdaui_new_cell_renderer (g_type, plugin);
-			cdata->data_cell = g_object_ref_sink ((GObject*) renderer);
+			cdata->data_cell = (GtkCellRenderer *) g_object_ref_sink ((GObject*) renderer);
 			g_hash_table_insert (grid->priv->columns_hash, renderer, cdata);
 			g_free (cdata->title);
 			cdata->title = title;
@@ -849,7 +849,7 @@ create_columns_data (GdauiRawGrid *grid)
 
 		/* Adding the GValue's information cell as another GtkCellRenderer */
 		renderer = gdaui_data_cell_renderer_info_new (grid->priv->store, grid->priv->iter, group);
-		cdata->info_cell = g_object_ref_sink ((GObject*) renderer);
+		cdata->info_cell = (GtkCellRenderer *) g_object_ref_sink ((GObject*) renderer);
 		g_hash_table_insert (grid->priv->columns_hash, renderer, cdata);
 		g_signal_connect (G_OBJECT (renderer), "status-changed",
 				  G_CALLBACK (data_cell_status_changed), grid);
@@ -2915,7 +2915,7 @@ paramlist_param_attr_changed_cb (G_GNUC_UNUSED GdaSet 
 		GtkCellRenderer *renderer;
 		gint model_col;
 		renderer = _gdaui_new_cell_renderer (gda_holder_get_g_type (param), plugin);
-		cdata->data_cell = g_object_ref_sink ((GObject*) renderer);
+		cdata->data_cell = (GtkCellRenderer *) g_object_ref_sink ((GObject*) renderer);
 		g_hash_table_insert (grid->priv->columns_hash, renderer, cdata);
 
 		model_col = g_slist_index (((GdaSet *)grid->priv->iter)->holders, param);
