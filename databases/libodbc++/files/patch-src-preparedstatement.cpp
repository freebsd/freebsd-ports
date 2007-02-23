--- src/preparedstatement.cpp.orig	Tue Jun 12 10:38:32 2001
+++ src/preparedstatement.cpp	Fri Feb 23 05:23:46 2007
@@ -161,7 +161,7 @@
   numParams_=np;
   
   SQLSMALLINT sqlType;
-  SQLUINTEGER prec;
+  SQLULEN prec;
   SQLSMALLINT scale;
   SQLSMALLINT nullable;
 
@@ -303,7 +303,7 @@
       r=SQLParamData(hstmt_,&currentCol);
       this->_checkStmtError(hstmt_,r,"SQLParamData failure");
       if(r==SQL_NEED_DATA) {
-	DataHandler* dh=rowset_->getColumn((int)currentCol);
+	DataHandler* dh=rowset_->getColumn((long)currentCol);
 
 	assert(dh->isStreamed_);
 	
