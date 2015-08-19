--- chessx.pro.orig	2015-05-05 13:46:26 UTC
+++ chessx.pro
@@ -393,6 +393,15 @@ macx {
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
 RESOURCES = resources.qrc
 
 TRANSLATIONS = i18n/chessx_de.ts \
