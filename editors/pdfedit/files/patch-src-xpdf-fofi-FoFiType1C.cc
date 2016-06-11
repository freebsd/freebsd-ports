--- src/xpdf/fofi/FoFiType1C.cc.orig	2016-06-11 10:45:36.260108000 +0900
+++ src/xpdf/fofi/FoFiType1C.cc	2016-06-11 10:46:10.103508000 +0900
@@ -2261,10 +2261,10 @@
   int pos, c, sid, nLeft, nSups, i, j;
 
   if (topDict.encodingOffset == 0) {
-    encoding = fofiType1StandardEncoding;
+    encoding = (char **)fofiType1StandardEncoding;
 
   } else if (topDict.encodingOffset == 1) {
-    encoding = fofiType1ExpertEncoding;
+    encoding = (char **)fofiType1ExpertEncoding;
 
   } else {
     encoding = (char **)gmallocn(256, sizeof(char *));
