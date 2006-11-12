--- src/statement.cpp.orig	Sun Nov 12 13:26:35 2006
+++ src/statement.cpp	Sun Nov 12 13:26:47 2006
@@ -672,7 +672,7 @@
 
   if(lastExecute_!=ODBC3_C(SQL_NO_DATA,SQL_NO_DATA_FOUND)) {
 
-    SQLINTEGER res;
+    SQLLEN res;
     SQLRETURN r=SQLRowCount(hstmt_,&res);
     this->_checkStmtError(hstmt_,r,"Error fetching update count");
     return res;
