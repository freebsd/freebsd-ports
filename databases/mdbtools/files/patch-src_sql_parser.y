--- src/sql/parser.y.orig	Tue Apr 15 01:26:03 2003
+++ src/sql/parser.y	Tue Apr 15 01:26:08 2003
@@ -109,6 +109,7 @@
 database:
 	PATH
 	|	NAME 
+	;
 
 table:
 	NAME { mdb_sql_add_table(_mdb_sql(NULL), $1); free($1); }
