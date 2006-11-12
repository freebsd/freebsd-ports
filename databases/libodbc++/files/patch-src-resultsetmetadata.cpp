--- src/resultsetmetadata.cpp.orig	Sun Nov 12 13:38:01 2006
+++ src/resultsetmetadata.cpp	Sun Nov 12 13:38:32 2006
@@ -39,7 +39,7 @@
 int ResultSetMetaData::_getNumericAttribute(unsigned int col,
 					   SQLUSMALLINT attr)
 {
-  SQLINTEGER res=0;
+  SQLLEN res=0;
   SQLRETURN r=
     ODBC3_C(SQLColAttribute,SQLColAttributes)(resultSet_->hstmt_,
 					      (SQLUSMALLINT)col,
@@ -63,7 +63,7 @@
   odbc::Deleter<char> _buf(buf,true);
   buf[maxlen]=0;
 
-  SQLINTEGER res=0;
+  SQLLEN res=0;
   SQLSMALLINT len=0;
 
   SQLRETURN r=
