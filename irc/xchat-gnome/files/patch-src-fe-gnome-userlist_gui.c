--- src/fe-gnome/userlist_gui.c.orig	Wed Oct 13 10:27:32 2004
+++ src/fe-gnome/userlist_gui.c	Wed Oct 13 10:28:46 2004
@@ -82,6 +82,7 @@
 {
 	GtkTreePath *path;
 	GtkTreeSelection *select;
+	struct User *u;
 	if (!event)
 		return FALSE;
 
@@ -105,7 +106,7 @@
 			gtk_tree_selection_select_path (select, path);
 			gtk_tree_path_free (path);
 		}
-		struct User *u = userlist_get_selected ();
+		u = userlist_get_selected ();
 		if (u != NULL)
 			userlist_context (view, u);
 		return TRUE;
