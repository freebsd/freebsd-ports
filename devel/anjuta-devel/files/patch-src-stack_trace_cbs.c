--- src/stack_trace_cbs.c.orig	Tue May 13 11:02:44 2003
+++ src/stack_trace_cbs.c	Tue May 13 11:03:51 2003
@@ -42,6 +42,8 @@
 	{
 		/* update the current index iterator and number in the stack trace object */
 		GtkTreeIter iter;
+		GdkEventButton *bevent;
+
 		if (!get_current_iter (st,&iter))
 			return FALSE;
 		
@@ -49,7 +51,7 @@
 		st->current_index_iter = gtk_tree_iter_copy (&iter);		
 		st->current_index = get_index_from_iter (st,&iter);
 				
-		GdkEventButton *bevent = (GdkEventButton *) event;
+		bevent = (GdkEventButton *) event;
 		if (bevent->button != 3)
 			return FALSE;
 		bevent->button = 1;
