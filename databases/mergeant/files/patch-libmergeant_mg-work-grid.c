--- libmergeant/mg-work-grid.c.orig	Sat Aug 14 03:59:47 2004
+++ libmergeant/mg-work-grid.c	Sat Aug 14 04:00:02 2004
@@ -2299,10 +2299,10 @@
 			      GtkTreeModel *tree_model, GtkTreeIter *iter,
 			      MgWorkCore *core, MgDataEntryAttribute requested_status)
 {
-	g_return_if_fail (user_modif);
 	guint attrs;
 	GtkTreePath *path;
 	gint row;
+	g_return_if_fail (user_modif);
 
 	switch (requested_status) {
 	case MG_DATA_ENTRY_IS_NULL:
