--- ocr-layout/ocr-reading-order.cc.orig	2009-05-31 20:18:41.000000000 +0000
+++ ocr-layout/ocr-reading-order.cc
@@ -210,7 +210,8 @@ namespace ocropus {
 
         // Make dummy text-lines from horizontal rulings to use them as
         // separating elements for reading order.
-        for(int i=0,l=hor_rulings.length(); i<l; i++){
+        int hrl;
+        for(int i=0,hrl=hor_rulings.length(); i<hrl; i++){
             line l;
             rectangle r = hor_rulings[i];
             l.c = r.ycenter();
