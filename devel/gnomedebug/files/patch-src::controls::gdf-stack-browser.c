
$FreeBSD$

--- src/controls/gdf-stack-browser.c	2001/10/23 13:31:23	1.1
+++ src/controls/gdf-stack-browser.c	2001/10/23 13:31:36
@@ -445,9 +445,9 @@
     GdkPixbuf *pixbufs[2];
 
     sb->priv->e_table_model = 
-        e_table_simple_new (col_count, row_count, value_at,
+        e_table_simple_new (col_count, row_count, NULL, value_at,
                             set_value_at, is_cell_editable,
-                            NULL, NULL, NULL,
+                            NULL, NULL, NULL, NULL, NULL,
                             value_is_empty,
                             value_to_string, sb);
     
