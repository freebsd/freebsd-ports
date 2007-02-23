--- src/resultset.cpp.orig	Fri Feb 23 05:24:16 2007
+++ src/resultset.cpp	Fri Feb 23 05:24:27 2007
@@ -528,7 +528,7 @@
       r=SQLParamData(hstmt_,&currentCol);
       this->_checkStmtError(hstmt_,r,"SQLParamData failure");
       if(r==SQL_NEED_DATA) {
-	DataHandler* dh=rowset_->getColumn((int)currentCol);
+	DataHandler* dh=rowset_->getColumn((long)currentCol);
 
 	assert(dh->isStreamed_);
 
