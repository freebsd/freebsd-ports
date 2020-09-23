--- ldb_mdb/ldb_mdb.c.orig	2019-06-13 03:07:34 UTC
+++ ldb_mdb/ldb_mdb.c
@@ -183,7 +183,7 @@ static int lmdb_store(struct ldb_kv_priv
 
 	if (flags == TDB_INSERT) {
 		mdb_flags = MDB_NOOVERWRITE;
-	} else if ((flags == TDB_MODIFY)) {
+	} else if (flags == TDB_MODIFY) {
 		/*
 		 * Modifying a record, ensure that it exists.
 		 * This mimics the TDB semantics
