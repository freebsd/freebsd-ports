--- kuickshow/src/kuickshow.cpp.orig	Sun Jan 29 12:32:04 2006
+++ kuickshow/src/kuickshow.cpp	Sun Jan 29 12:44:27 2006
@@ -646,7 +646,7 @@
     }
 
     tryShowNextImage();
-    fileWidget->trash(list, false, false);
+    fileWidget->trash(list, parent, false, false);
 }
 
 void KuickShow::tryShowNextImage()
