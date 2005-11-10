
$FreeBSD$

--- src/plot.c.orig
+++ src/plot.c
@@ -277,8 +277,8 @@
 {
 	GtkTreeIter iter;
 	GtkTreeModel *model;
-	plot->selected = 0;
 	gboolean activo;
+	plot->selected = 0;
 
 	/* Check if selected row is leaf or root */
 	if (gtk_tree_path_get_depth (arg1) == 1) {
