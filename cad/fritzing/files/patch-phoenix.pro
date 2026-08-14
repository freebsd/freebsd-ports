--- phoenix.pro.orig	2026-07-28 07:36:38 UTC
+++ phoenix.pro
@@ -19,11 +19,10 @@ QT_LEAST=6.5.3
 # ********************************************************************
 
 QT_LEAST=6.5.3
-QT_MOST=6.10.10
+QT_MOST=6.11.1
 !versionAtLeast(QT_VERSION, $${QT_LEAST}):error("Use at least Qt version $${QT_LEAST}")
 !versionAtMost(QT_VERSION, $${QT_MOST}):error("Use at most Qt version $${QT_MOST}")
 
-CONFIG += debug_and_release
 CONFIG += c++20
 
 unix {
@@ -130,7 +129,7 @@ unix {
     manpage.files += Fritzing.1
 
     icon.path = $$DATADIR/pixmaps
-    icon.extra = install -D -m 0644 $$PWD/resources/images/fritzing_icon.png $(INSTALL_ROOT)$$DATADIR/pixmaps/fritzing.png
+    icon.extra = install -m 0644 $$PWD/resources/images/fritzing_icon.png $(INSTALL_ROOT)$$DATADIR/pixmaps/fritzing.png
 
     parts.path = $$PKGDATADIR
     parts.files += parts
