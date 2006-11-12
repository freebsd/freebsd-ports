--- src/datastream.h.orig	Mon Apr 21 16:28:38 2003
+++ src/datastream.h	Sun Nov 12 13:36:35 2006
@@ -49,7 +49,7 @@
     SQLHSTMT hstmt_;
     int column_;
     int cType_;
-    SQLINTEGER& dataStatus_;
+    SQLLEN& dataStatus_;
     size_t bufferSize_;
 
     virtual int underflow();
@@ -63,7 +63,13 @@
       return 0;
     }
     
-    virtual int showmanyc() {
+    virtual
+#if !defined(ODBCXX_HAVE_ISO_CXXLIB) 
+    int
+#else
+    std::streamsize
+#endif
+    showmanyc() {
       if(this->gptr() < this->egptr()) {
 	return this->egptr() - this->gptr();
       }
@@ -71,7 +77,7 @@
     }
 
     DataStreamBuf(ErrorHandler* eh, SQLHSTMT hstmt, int col, int cType,
-		  SQLINTEGER& dataStatus);
+		  SQLLEN& dataStatus);
     virtual ~DataStreamBuf();
   };
 
@@ -102,7 +108,7 @@
     friend class Rowset;
   private:
     DataStream(ErrorHandler* eh, SQLHSTMT hstmt, int column, int cType,
-	       SQLINTEGER& ds)
+	       SQLLEN& ds)
       :
 #if !defined(ODBCXX_HAVE_ISO_CXXLIB)
       DataStreamBase(eh,hstmt,column,cType,ds),std::istream(this->rdbuf())
