--- src/playlist2.c.orig	Mon Jul 12 17:46:23 2004
+++ src/playlist2.c	Sun Jul 25 17:38:51 2004
@@ -609,10 +609,10 @@
 	/* move every dragged row */
 	if (gtk_tree_selection_count_selected_rows (selection) > 0)
 	{
+		int i = 0;
 		GList *list = NULL;
 		list = gtk_tree_selection_get_selected_rows (selection, &pl2_fil);
 		list = g_list_last (list);
-		int i = 0;
 		/* start a command list */
 		mpd_sendCommandListBegin (info.connection);
 		do
