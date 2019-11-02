--- iqpuzzle.pro.orig	2019-11-02 16:27:16 UTC
+++ iqpuzzle.pro
@@ -108,7 +108,7 @@ unix: !macx {
     icons.path     = $$PREFIX/share/icons
     icons.files   += res/images/hicolor
 
-    man.path       = $$PREFIX/share
+    man.path       = $$PREFIX
     man.files     += man
 
     meta.path      = $$PREFIX/share/metainfo
