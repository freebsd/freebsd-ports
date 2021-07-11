--- src/plugins/sqldrivers/mysql/qsql_mysql.cpp.orig	2020-10-27 08:02:11 UTC
+++ src/plugins/sqldrivers/mysql/qsql_mysql.cpp
@@ -352,11 +360,11 @@ void QMYSQLResultPrivate::bindBlobs()
 
     for(i = 0; i < fields.count(); ++i) {
         fieldInfo = fields.at(i).myField;
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
