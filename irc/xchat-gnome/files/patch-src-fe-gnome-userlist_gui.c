--- src/fe-gnome/userlist_gui.c.orig	Sun Apr 25 01:14:29 2004
+++ src/fe-gnome/userlist_gui.c	Wed May  5 00:16:02 2004
@@ -64,13 +64,14 @@
 	}
 
 	if(event->button == 3) {
+		struct User *u;
 		if(gtk_tree_view_get_path_at_pos(GTK_TREE_VIEW(view), event->x, event->y, &path, 0, 0, 0)) {
 			select = gtk_tree_view_get_selection(GTK_TREE_VIEW(view));
 			gtk_tree_selection_unselect_all(select);
 			gtk_tree_selection_select_path(select, path);
 			gtk_tree_path_free(path);
 		}
-		struct User *u = userlist_get_selected();
+		u = userlist_get_selected();
 		if(u != NULL)
 			userlist_context(view, u);
 		return TRUE;
