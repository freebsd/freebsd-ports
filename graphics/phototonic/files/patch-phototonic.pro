--- phototonic.pro.orig	2015-11-08 18:03:52 UTC
+++ phototonic.pro
@@ -17,19 +17,19 @@ SOURCES += dialogs.cpp main.cpp mainwind
 			mdcache.cpp
 RESOURCES += phototonic.qrc
 
-target.path = /usr/bin/
+target.path = %%PREFIX%%/bin/
 
 icon.files = images/phototonic.png
-icon.path = /usr/share/icons/hicolor/48x48/apps
+icon.path = %%PREFIX%%/share/icons/hicolor/48x48/apps
 
 icon16.files = images/icon16/phototonic.png
-icon16.path = /usr/share/icons/hicolor/16x16/apps
+icon16.path = %%PREFIX%%/share/icons/hicolor/16x16/apps
 
 iconPixmaps.files = images/icon16/phototonic.png
-iconPixmaps.path = /usr/share/pixmaps
+iconPixmaps.path = %%PREFIX%%/share/pixmaps
 
 desktop.files = phototonic.desktop
-desktop.path = /usr/share/applications
+desktop.path = %%PREFIX%%/share/applications
 
 INSTALLS += target icon icon16 iconPixmaps desktop
 
