--- libedataserverui/e-name-selector-entry.c.orig	Mon Oct  3 11:05:48 2005
+++ libedataserverui/e-name-selector-entry.c	Thu Nov 10 10:23:46 2005
@@ -1112,7 +1112,7 @@
 	const gchar *text;
 	gint         index_start, index_end;
 	gint	     selection_start, selection_end;	
-	gunichar     str_context [2], str_b_context [2];;
+	gunichar     str_context [2], str_b_context [2];
 	gint         len;
 	gint         i;
 	gboolean     already_selected = FALSE;
