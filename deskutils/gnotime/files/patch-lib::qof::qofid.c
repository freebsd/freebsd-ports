--- lib/qof/qofid.c.orig	Sun May 23 22:57:30 2004
+++ lib/qof/qofid.c	Sun Jul  4 23:00:04 2004
@@ -182,8 +182,9 @@
 static void
 qof_collection_remove_entity (QofEntity *ent)
 {
+  QofCollection *col;
   if (!ent) return;
-  QofCollection *col = ent->collection;
+  col = ent->collection;
   if (!col) return;
   g_hash_table_remove (col->hash_of_entities, &ent->guid);
   ent->collection = NULL;
