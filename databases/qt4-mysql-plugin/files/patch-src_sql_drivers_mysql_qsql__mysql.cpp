https://dev.mysql.com/doc/relnotes/mysql/8.0/en/news-8-0-1.html 

Incompatible Change: The my_bool type is no longer used in MySQL 
source code. Any third-party code that used this type to represent 
C boolean variables should use the bool or int C type instead.

Note
The change from my_bool to bool means that the mysql.h header file 
now requires a C++ or C99 compiler to compile.

(Bug #25597667)

--- src/sql/drivers/mysql/qsql_mysql.cpp.orig	2015-05-07 14:14:48 UTC
+++ src/sql/drivers/mysql/qsql_mysql.cpp
@@ -74,6 +74,14 @@ Q_DECLARE_METATYPE(MYSQL_STMT*)
 #  define Q_CLIENT_MULTI_STATEMENTS 0
 #endif
 
+// MYSQL 8.0.1 no longer uses the my_bool type:
+// https://dev.mysql.com/doc/relnotes/mysql/8.0/en/news-8-0-1.html
+#if MYSQL_VERSION_ID >= 80001
+typedef bool mysql_bool;
+#else
+typedef my_bool mysql_bool;
+#endif
+
 QT_BEGIN_NAMESPACE
 
 class QMYSQLDriverPrivate
@@ -194,7 +202,7 @@ class QMYSQLResultPrivate : public QObject (public)
               myField(0), type(QVariant::Invalid)
         {}
         char *outField;
-        my_bool nullIndicator;
+        mysql_bool nullIndicator;
         ulong bufLength;
         MYSQL_FIELD *myField;
         QVariant::Type type;
@@ -930,7 +938,7 @@ bool QMYSQLResult::exec()
     MYSQL_BIND* currBind;
     QVector<MYSQL_TIME *> timeVector;
     QVector<QByteArray> stringVector;
-    QVector<my_bool> nullVector;
+    QVector<mysql_bool> nullVector;
 
     const QVector<QVariant> values = boundValues();
 
@@ -951,7 +959,7 @@ bool QMYSQLResult::exec()
 
             currBind = &d->outBinds[i];
 
-            nullVector[i] = static_cast<my_bool>(val.isNull());
+            nullVector[i] = static_cast<mysql_bool>(val.isNull());
             currBind->is_null = &nullVector[i];
             currBind->length = 0;
             currBind->is_unsigned = 0;
@@ -1048,7 +1056,7 @@ bool QMYSQLResult::exec()
     d->rowsAffected = mysql_stmt_affected_rows(d->stmt);
 
     if (isSelect()) {
-        my_bool update_max_length = true;
+        mysql_bool update_max_length = true;
 
         r = mysql_stmt_bind_result(d->stmt, d->inBinds);
         if (r != 0) {
@@ -1245,7 +1253,7 @@ bool QMYSQLDriver::open(const QString& db,
     const QStringList opts(connOpts.split(QLatin1Char(';'), QString::SkipEmptyParts));
     QString unixSocket;
 #if MYSQL_VERSION_ID >= 50000
-    my_bool reconnect=false;
+    mysql_bool reconnect=false;
 #endif
 
     // extract the real options from the string
