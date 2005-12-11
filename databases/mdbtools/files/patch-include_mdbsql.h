--- include/mdbsql.h.orig	Sun Dec 11 18:22:34 2005
+++ include/mdbsql.h	Sun Dec 11 18:23:20 2005
@@ -6,6 +6,10 @@
 #ifndef _mdbsql_h_
 #define _mdbsql_h_
 
+#ifdef __cplusplus
+extern "C" {
+#endif
+
 typedef struct {
 	MdbHandle *mdb;
 	int all_columns;
@@ -59,4 +63,7 @@
 void mdb_sql_listtables(MdbSQL *sql);
 void mdb_sql_select(MdbSQL *sql);
 
+#ifdef __cplusplus
+}
+#endif
 #endif
