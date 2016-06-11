--- src/xpdf/fofi/FoFiType1C.cc.orig	2009-09-11 12:02:56 UTC
+++ src/xpdf/fofi/FoFiType1C.cc
@@ -2261,10 +2261,10 @@ void FoFiType1C::buildEncoding() {
   int pos, c, sid, nLeft, nSups, i, j;
 
   if (topDict.encodingOffset == 0) {
-    encoding = fofiType1StandardEncoding;
+    encoding = (char **)fofiType1StandardEncoding;
 
   } else if (topDict.encodingOffset == 1) {
-    encoding = fofiType1ExpertEncoding;
+    encoding = (char **)fofiType1ExpertEncoding;
 
   } else {
     encoding = (char **)gmallocn(256, sizeof(char *));
