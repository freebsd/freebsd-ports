--- src/preproc/grn/main.cc.bak	2013-12-26 00:51:09.467987940 +0900
+++ src/preproc/grn/main.cc	2013-12-26 00:52:24.577939911 +0900
@@ -160,7 +160,7 @@
 double scale = 1.0;		/* no scaling, default */
 int defpoint = 0;		/* flag for pointsize scaling */
 char *defstipple = (char *) 0;
-enum {
+enum filltype {
   OUTLINE, FILL, BOTH
 } polyfill;
 
