--- src/plugins/sqldrivers/mysql/qsql_mysql.cpp.orig	2023-09-04 21:23:22 UTC
+++ src/plugins/sqldrivers/mysql/qsql_mysql.cpp
@@ -363,11 +363,11 @@ void QMYSQLResultPrivate::bindBlobs()
     MYSQL_BIND *bind;
     for (int i = 0; i < fields.count(); ++i) {
         const MYSQL_FIELD *fieldInfo = fields.at(i).myField;
-        if (qIsBlob(inBinds[i].buffer_type) && meta && fieldInfo) {
+        if (qIsBlob(inBinds[i].buffer_type) && meta && fieldInfo && fieldInfo->max_length) {
             bind = &inBinds[i];
             bind->buffer_length = fieldInfo->max_length;
             delete[] static_cast<char*>(bind->buffer);
-            bind->buffer = new char[fieldInfo->max_length];
+            bind->buffer = new char[bind->buffer_length];
             fields[i].outField = static_cast<char*>(bind->buffer);
         }
     }
