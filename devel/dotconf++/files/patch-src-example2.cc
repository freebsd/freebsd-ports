--- src/example2/example2.cc.orig	Wed May 14 17:10:26 2003
+++ src/example2/example2.cc	Wed Jul 13 20:21:29 2005
@@ -51,7 +51,7 @@
 
 int main(int argc, char * argv[])
 {    
-    DOTCONFDocument conf(DOTCONFDocument::CASEINSENSETIVE);
+    DOTCONFDocument conf(DOTCONFDocument::CASEINSENSITIVE);
 
     conf.setRequiredOptionNames(requiredOptions);
 
