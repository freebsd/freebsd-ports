--- main.pro.orig	2010-01-11 05:30:10.000000000 +0200
+++ main.pro	2010-01-11 05:30:24.000000000 +0200
@@ -26,10 +26,6 @@
     }
   }
 
-  unix:!macx {
-    SUBDIRS *= overlay_gl
-  }
-
   macx {
     SUBDIRS *= overlay_macx
     !CONFIG(no-g15) {
