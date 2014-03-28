--- chessx.pro_orig	2014-03-21 10:53:31.321941038 +0100
+++ chessx.pro	2014-03-21 10:54:00.294938611 +0100
@@ -323,6 +323,15 @@
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
