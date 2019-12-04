--- Photoflare.pro.orig	2019-04-26 18:57:02 UTC
+++ Photoflare.pro
@@ -235,7 +235,7 @@ unix:!macx {
     pixmaps.files = installers/deb/DEBIAN/usr/share/icons/hicolor/48x48/apps/photoflare.png
     desktopentry.path = $${BASEDIR}$${PREFIX}/share/applications
     desktopentry.files = installers/deb/DEBIAN/usr/share/applications/$${TARGET}.desktop
-    manpage.path = $${PREFIX}/share/man/man1/
+    manpage.path = $${PREFIX}/man/man1/
     manpage.files = photoflare.1
     appstream.path = $${PREFIX}/share/metainfo/
     appstream.files = io.photoflare.photoflare.appdata.xml
