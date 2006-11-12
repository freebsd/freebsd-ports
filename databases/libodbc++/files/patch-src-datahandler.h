--- src/datahandler.h.orig	Sun Nov 12 13:34:24 2006
+++ src/datahandler.h	Sun Nov 12 13:33:01 2006
@@ -48,7 +48,7 @@
     size_t rows_;
     char* buffer_;
     size_t bufferSize_;
-    SQLINTEGER* dataStatus_;
+    SQLLEN* dataStatus_;
     bool isStreamed_;
     ODBCXX_STREAM* stream_;
     bool ownStream_;
@@ -84,11 +84,11 @@
       return &buffer_[bufferSize_*currentRow_];
     }
 
-    void setDataStatus(SQLINTEGER i) {
+    void setDataStatus(SQLLEN i) {
       dataStatus_[currentRow_]=i;
     }
     
-    SQLINTEGER getDataStatus() const {
+    SQLLEN getDataStatus() const {
       return dataStatus_[currentRow_];
     }
 
