--- src/example1/example1.cc.orig	Sat Apr 10 15:22:00 2004
+++ src/example1/example1.cc	Wed Jul 13 20:20:47 2005
@@ -54,7 +54,7 @@
 
 int main()
 {    
-    DOTCONFDocument *conf = new DOTCONFDocument(DOTCONFDocument::CASEINSENSETIVE);
+    DOTCONFDocument *conf = new DOTCONFDocument(DOTCONFDocument::CASEINSENSITIVE);
     const DOTCONFDocumentNode * node = NULL;
     const char * v = NULL;
     char * fqdn = NULL;
