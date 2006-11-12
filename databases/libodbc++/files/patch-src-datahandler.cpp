--- src/datahandler.cpp.orig	Sun Nov 12 13:34:06 2006
+++ src/datahandler.cpp	Sun Nov 12 13:33:23 2006
@@ -269,7 +269,7 @@
   };
   this->setupBuffer(bs);
 
-  dataStatus_=new SQLINTEGER[rows_];
+  dataStatus_=new SQLLEN[rows_];
 
   //set everything to NULL
   for(unsigned int i=0; i<rows_; i++) {
