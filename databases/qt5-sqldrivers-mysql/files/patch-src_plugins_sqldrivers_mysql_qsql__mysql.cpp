https://dev.mysql.com/doc/relnotes/mysql/8.0/en/news-8-0-1.html

Incompatible Change: The my_bool type is no longer used in MySQL
source code. Any third-party code that used this type to represent
C boolean variables should use the bool or int C type instead.

Note
The change from my_bool to bool means that the mysql.h header file
now requires a C++ or C99 compiler to compile.

(Bug #25597667)

For Qt5, which requires C++11, the following line single-line
definition for mysql_bool is less-fragile and more C++y:
	using mysql_bool = decltype(MYSQL_BIND::is_null_value);
This does not apply to the Qt4 port, which allows older compilers
and the less-fragile approach would therefore break on old-gcc-in-base
architectures.

--- src/plugins/sqldrivers/mysql/qsql_mysql.cpp.orig	2020-03-11 15:29:12 UTC
+++ src/plugins/sqldrivers/mysql/qsql_mysql.cpp
@@ -71,6 +71,14 @@ Q_DECLARE_METATYPE(MYSQL_STMT*)
 // by redefining it we can regain source compatibility.
 using my_bool = decltype(mysql_stmt_bind_result(nullptr, nullptr));
 
+// MYSQL 8.0.1 no longer uses the my_bool type:
+// https://dev.mysql.com/doc/relnotes/mysql/8.0/en/news-8-0-1.html
+#if (MYSQL_VERSION_ID >= 80001) && !defined(MARIADB_BASE_VERSION)
+typedef bool mysql_bool;
+#else
+typedef my_bool mysql_bool;
+#endif
+
 QT_BEGIN_NAMESPACE
 
 class QMYSQLDriverPrivate : public QSqlDriverPrivate
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
