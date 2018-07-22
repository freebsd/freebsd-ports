--- chessx.pro.orig	2018-07-21 09:39:34 UTC
+++ chessx.pro
@@ -445,6 +445,16 @@ macx {
  QMAKE_INFO_PLIST = mac_osx/Info.plist
 }
 
+unix:!macx {
+ target.path = $$PREFIX/bin
+ pixmaps.path = $$PREFIX/share/pixmaps
+ pixmaps.files = data/images/chessx.png
+ desktop.path = $$PREFIX/share/applications
+ desktop.files = unix/chessx.desktop
+ INSTALLS += target desktop pixmaps
+}
+
+
 RESOURCES = \
     resources.qrc
 
