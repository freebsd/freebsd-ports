
$FreeBSD$

--- src/controls/gdf-breakpoint-manager.c	2001/10/23 13:25:05	1.1
+++ src/controls/gdf-breakpoint-manager.c	2001/10/23 13:25:09
@@ -468,8 +468,8 @@
 create_children (GdfBreakpointManager *bpm)
 {   
     bpm->priv->e_table_model
-        = e_table_simple_new (col_count, row_count, value_at, set_value_at, 
-                              is_cell_editable, NULL, NULL, NULL, 
+        = e_table_simple_new (col_count, row_count, NULL, value_at, set_value_at, 
+                              is_cell_editable, NULL, NULL, NULL, NULL, NULL, 
                               value_is_empty, value_to_string, bpm);
                              
     bpm->priv->e_table = e_table_scrolled_new (bpm->priv->e_table_model, 
