--- src/dotconfpp.h.orig	Wed May 14 19:10:26 2003
+++ src/dotconfpp.h	Thu Jul  7 17:02:43 2005
@@ -75,7 +75,7 @@
 class DOTCONFDocument
 {
 public:
-    enum CaseSensitive { CASESENSETIVE, CASEINSENSETIVE };
+    enum CaseSensitive { CASESENSITIVE, CASEINSENSITIVE };
 protected:
     AsyncDNSMemPool * mempool; 
 private:
@@ -103,7 +103,7 @@
     virtual void error(int lineNum, const char * fileName, const char * fmt, ...);
 
 public:
-    DOTCONFDocument(CaseSensitive caseSensitivity = CASESENSETIVE);
+    DOTCONFDocument(CaseSensitive caseSensitivity = CASESENSITIVE);
     virtual ~DOTCONFDocument();
 
     int setContent(const char * _fileName);
