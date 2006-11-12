--- src/datastream.cpp.orig	Sun Nov 12 13:36:46 2006
+++ src/datastream.cpp	Sun Nov 12 13:39:05 2006
@@ -30,7 +30,7 @@
 #if !defined(ODBCXX_QT)
 
 DataStreamBuf::DataStreamBuf(ErrorHandler* eh, SQLHSTMT hstmt, int col, 
-			     int cType,SQLINTEGER& dataStatus)
+			     int cType,SQLLEN& dataStatus)
   :errorHandler_(eh), 
    hstmt_(hstmt), 
    column_(col), 
@@ -78,7 +78,7 @@
   
   //after the call, this is the number of bytes that were 
   //available _before_ the call
-  SQLINTEGER bytes;
+  SQLLEN bytes;
 
   //the actual number of bytes that should end up in our buffer
   //we don't care about NULL termination
@@ -134,7 +134,7 @@
 // really ugly
 
 DataStream::DataStream(ErrorHandler* eh, SQLHSTMT hstmt, int col, 
-		       int cType,SQLINTEGER& dataStatus)
+		       int cType,SQLLEN& dataStatus)
   :errorHandler_(eh), 
    hstmt_(hstmt), 
    column_(col), 
