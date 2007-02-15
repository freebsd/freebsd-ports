--- kexi/kexidb/drivers/pqxx/pqxxdriver.cpp.orig	Sun Feb 11 16:38:08 2007
+++ kexi/kexidb/drivers/pqxx/pqxxdriver.cpp	Sun Feb 11 17:29:18 2007
@@ -133,14 +133,14 @@
 //
 QString pqxxSqlDriver::escapeString( const QString& str) const
 {
-    return QString(pqxx::Quote(str.ascii()).c_str());
+    return "'"+QString(pqxx::sqlesc(str.ascii()).c_str())+"'";
 }
 
 //==================================================================================
 //
 QCString pqxxSqlDriver::escapeString( const QCString& str) const
 {
-    return QCString(pqxx::Quote(QString(str).ascii()).c_str());
+    return "'"+QCString(pqxx::sqlesc(QString(str).ascii()).c_str())+"'";
 }
 
 //==================================================================================
