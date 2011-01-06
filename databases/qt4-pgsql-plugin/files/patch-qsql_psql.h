--- ./src/sql/drivers/psql/qsql_psql.h	2010-09-10 11:05:25.000000000 +0200
+++ ./src/sql/drivers/psql/qsql_psql.h	2010-11-03 12:36:16.380310668 +0100
@@ -104,7 +104,8 @@
         Version74 = 10,
         Version8 = 11,
         Version81 = 12,
-        Version82 = 13
+        Version82 = 13,
+        Version9 = 14
     };
 
     explicit QPSQLDriver(QObject *parent=0);
