--- src/attach_process.c.orig	Fri Jan 30 20:16:25 2004
+++ src/attach_process.c	Fri Jan 30 20:20:48 2004
@@ -170,11 +170,12 @@
 static gboolean
 iter_stack_pop (AttachProcess *ap)
 {
+	GtkTreeIter *iter;
+
 	if (ap->priv->iter_stack_level < 0)
 		return FALSE;
 
-	GtkTreeIter *iter =
-			(GtkTreeIter *) (g_slist_nth_data (ap->priv->iter_stack, 0));
+	iter = (GtkTreeIter *) (g_slist_nth_data (ap->priv->iter_stack, 0));
 	ap->priv->iter_stack =
 			g_slist_delete_link (ap->priv->iter_stack, ap->priv->iter_stack);
 	g_free (iter);
