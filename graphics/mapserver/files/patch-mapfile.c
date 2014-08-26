--- mapfile.c.orig	2014-08-26 20:37:17.000000000 +0800
+++ mapfile.c	2014-08-26 20:38:39.000000000 +0800
@@ -3398,7 +3398,7 @@
 
   /* reset labels */
   for(i=0; i<class->numlabels; i++) {
-    if(class->styles[i] != NULL) {
+    if(class->labels[i] != NULL) {
       if(freeLabel(class->labels[i]) == MS_SUCCESS ) {
         msFree(class->labels[i]);
       }
