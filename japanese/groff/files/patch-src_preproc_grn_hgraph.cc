--- src/preproc/grn/hgraph.cc.bak	2013-12-26 00:50:57.243769618 +0900
+++ src/preproc/grn/hgraph.cc	2013-12-26 00:52:09.513467616 +0900
@@ -43,7 +43,7 @@
 extern int ybottom;
 extern int xleft;
 extern int xright;
-extern enum {
+extern enum filltype {
   OUTLINE, FILL, BOTH
 } polyfill;
 
