--- dao/ScsiIf-lib.cc.orig	Tue Oct 29 19:40:39 2002
+++ dao/ScsiIf-lib.cc	Tue Oct 29 20:14:24 2002
@@ -204,7 +204,7 @@
   scmd->cdb_len = cmdLen;
 
   if (dataOutLen > 0) {
-    if (((unsigned)dataOut % impl_->pageSize_) != 0) {
+    if (((size_t)dataOut % impl_->pageSize_) != 0) {
       //message(0, "Use SCSI buffer for data out.");
       memcpy(impl_->pageAlignedBuffer_, dataOut, dataOutLen);
       scmd->addr = impl_->pageAlignedBuffer_;
@@ -217,7 +217,7 @@
     scmd->size = dataOutLen;
   }
   else if (dataInLen > 0) {
-    if (((unsigned)dataIn % impl_->pageSize_) != 0) {
+    if (((size_t)dataIn % impl_->pageSize_) != 0) {
       //message(0, "Use SCSI buffer for data in.");
       scmd->addr = impl_->pageAlignedBuffer_;
       usedPageAlignedBuffer = 1;
