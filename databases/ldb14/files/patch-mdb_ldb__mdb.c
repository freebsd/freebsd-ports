--- ldb_mdb/ldb_mdb.c.orig	2018-07-12 08:23:36 UTC
+++ ldb_mdb/ldb_mdb.c
@@ -40,7 +40,9 @@ int ldb_mdb_err_map(int lmdb_err)
 		return LDB_SUCCESS;
 	case EIO:
 		return LDB_ERR_OPERATIONS_ERROR;
+#ifdef EBADE
 	case EBADE:
+#endif
 	case MDB_INCOMPATIBLE:
 	case MDB_CORRUPTED:
 	case MDB_INVALID:
@@ -181,7 +183,7 @@ static int lmdb_store(struct ltdb_privat
 
 	if (flags == TDB_INSERT) {
 		mdb_flags = MDB_NOOVERWRITE;
-	} else if ((flags == TDB_MODIFY)) {
+	} else if (flags == TDB_MODIFY) {
 		/*
 		 * Modifying a record, ensure that it exists.
 		 * This mimics the TDB semantics
