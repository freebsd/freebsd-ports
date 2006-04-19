--- rhythmdb/rhythmdb-query-model.c.orig	Mon Apr 17 03:09:23 2006
+++ rhythmdb/rhythmdb-query-model.c	Mon Apr 17 03:09:35 2006
@@ -2191,8 +2191,8 @@ rhythmdb_query_model_album_sort_func (Rh
 {
 	const char *a_val;
 	const char *b_val;
-	ulong a_num;
-	ulong b_num;
+	gulong a_num;
+	gulong b_num;
 	gint ret;
 
 	/* Sort by album name */
