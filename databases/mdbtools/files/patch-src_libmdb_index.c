--- src/libmdb/index.c.orig	2020-12-17 19:03:05 UTC
+++ src/libmdb/index.c
@@ -1104,7 +1104,7 @@ mdb_index_scan_init(MdbHandle *mdb, MdbTableDef *table
 {
 	int i;
 
-	if (mdb_get_option(MDB_USE_INDEX) && mdb_choose_index(table, &i) == MDB_INDEX_SCAN) {
+	if ((IS_JET3(mdb) || mdb_get_option(MDB_USE_INDEX)) && mdb_choose_index(table, &i) == MDB_INDEX_SCAN) {
 		table->strategy = MDB_INDEX_SCAN;
 		table->scan_idx = g_ptr_array_index (table->indices, i);
 		table->chain = g_malloc0(sizeof(MdbIndexChain));
