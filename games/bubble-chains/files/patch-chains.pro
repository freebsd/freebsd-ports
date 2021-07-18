--- chains.pro.orig	2020-12-22 07:59:21 UTC
+++ chains.pro
@@ -13,26 +13,26 @@ QMAKE_TARGET_COMPANY =
 
 unix: {
     TARGET = ./bin/chains
-    target.path = /usr/local/bin
+    target.path = $$PREFIX/bin
     INSTALLS += target
 
-    datas.path = /usr/share/games/chains
+    datas.path = $$DATADIR
     datas.files = data
     INSTALLS += datas
 	
-    desktop.path = /usr/share/applications/
+    desktop.path = $$PREFIX/share/applications/
     desktop.files = setup.linux/chains.desktop
     INSTALLS += desktop
 	
-    icon.path = /usr/share/icons/hicolor/256x256/apps/
+    icon.path = $$PREFIX/share/icons/hicolor/256x256/apps/
     icon.files = setup.linux/chains.png
     INSTALLS += icon
 
-    icon2.path = /usr/share/pixmaps
+    icon2.path = $$PREFIX/share/pixmaps
     icon2.files = setup.linux/chains.png
     INSTALLS += icon2
 
-    appdata.path = /usr/share/appdata/
+    appdata.path = $$PREFIX/share/appdata/
     appdata.files = setup.linux/chains.appdata.xml
     INSTALLS += appdata
 	
