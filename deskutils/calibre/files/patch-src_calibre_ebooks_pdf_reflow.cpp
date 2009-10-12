--- src/calibre/ebooks/pdf/reflow.cpp.orig	2009-10-11 23:21:41.000000000 +0400
+++ src/calibre/ebooks/pdf/reflow.cpp	2009-10-11 23:25:18.000000000 +0400
@@ -669,7 +669,7 @@
 				  int width, int height, GBool invert,
 				  GBool interpolate, GBool inlineImg) {
     OutputDev::drawImageMask(state, ref, str, width, height,
-            invert, interpolate, inlineImg);
+            invert, inlineImg);
     //this->images->add_mask();
     cerr << "mask requested" << endl;
 }
