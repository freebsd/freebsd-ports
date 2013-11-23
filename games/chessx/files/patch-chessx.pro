--- ./chessx.pro.orig	2013-10-30 20:52:41.000000000 +0000
+++ ./chessx.pro	2013-11-18 16:36:14.764197702 +0000
@@ -309,17 +309,14 @@
 }
 
 unix:!macx {
- target.path = /usr/local/bin/chessx
- pixmaps.path = /usr/share/pixmaps
+ target.path = $$PREFIX/bin
+ pixmaps.path = $$PREFIX/share/pixmaps
  pixmaps.files = data/images/chessx.png
- desktop.path = /usr/share/applications
- desktop.files = chessx.desktop
- desktop.extra += xdg-mime install --mode system chessx-x-chess-pgn.xml &&
- desktop.extra += xdg-mime default chessx.desktop application/x-chess-pgn &&
- desktop.extra += xdg-icon-resource install --context mimetypes --size 32 ./data/images/chessx-32.png application-x-chess-pgn &&
- desktop.extra += xdg-icon-resource install --context mimetypes --size 64 ./data/images/chessx-64.png application-x-chess-pgn &&
- desktop.extra += xdg-icon-resource install --context mimetypes --size 128 ./data/images/chessx.png application-x-chess-pgn
- INSTALLS += target desktop pixmaps
+ desktop.path = $$PREFIX/share/applications
+ desktop.files = unix/chessx.desktop
+ mime.path = $$PREFIX/share/mime/packages
+ mime.files += unix/chessx-x-chess-pgn.xml
+ INSTALLS += target desktop pixmaps mime
 }
 
 RESOURCES = resources.qrc
