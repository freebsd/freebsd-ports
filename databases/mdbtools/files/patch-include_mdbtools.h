--- include/mdbtools.h.orig	Sun Dec 11 18:22:42 2005
+++ include/mdbtools.h	Sun Dec 11 18:23:32 2005
@@ -40,6 +40,10 @@
 #define MDB_MEMO_OVERHEAD 12
 #define MDB_BIND_SIZE 16384
 
+#ifdef __cplusplus
+extern "C" {
+#endif
+
 enum {
 	MDB_PAGE_DB = 0,
 	MDB_PAGE_DATA,
@@ -345,4 +349,8 @@
 /* index.c */
 extern GPtrArray *mdb_read_indices(MdbTableDef *table);
 extern void mdb_index_dump(MdbTableDef *table, MdbIndex *idx);
+
+#ifdef __cplusplus
+}
+#endif
 #endif /* _mdbtools_h_ */
