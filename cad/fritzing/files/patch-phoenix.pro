--- phoenix.pro.orig	2025-10-14 05:29:12 UTC
+++ phoenix.pro
@@ -127,7 +127,7 @@ unix {
     manpage.files += Fritzing.1
 
     icon.path = $$DATADIR/pixmaps
-    icon.extra = install -D -m 0644 $$PWD/resources/images/fritzing_icon.png $(INSTALL_ROOT)$$DATADIR/pixmaps/fritzing.png
+    icon.extra = install -m 0644 $$PWD/resources/images/fritzing_icon.png $(INSTALL_ROOT)$$DATADIR/pixmaps/fritzing.png
 
     parts.path = $$PKGDATADIR
     parts.files += parts
