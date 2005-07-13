--- src/dotconfpp.cc.orig	Fri Jun 25 14:03:20 2004
+++ src/dotconfpp.cc	Thu Jul  7 17:03:58 2005
@@ -53,7 +53,7 @@
     mempool(NULL),
     curParent(NULL), curPrev(NULL), curLine(0), file(NULL), fileName(NULL)
 {
-    if(caseSensitivity == CASESENSETIVE){
+    if(caseSensitivity == CASESENSITIVE){
         cmp_func = strcmp;
     } else {
         cmp_func = strcasecmp;
