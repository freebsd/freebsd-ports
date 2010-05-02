--- ./textroom.pro.orig	2010-04-21 18:41:54.000000000 +0400
+++ ./textroom.pro	2010-05-01 02:27:57.894111731 +0400
@@ -7,9 +7,9 @@
 INCLUDEPATH += . \
     src \
     src/include \
-    /usr/include \
-    /usr/include/hunspell \
-    /usr/include/SDL
+    $$LOCALBASE/include \
+    $$LOCALBASE/include/hunspell \
+    $$LOCALBASE/include/SDL
 DESTDIR += .
 OBJECTS_DIR += temp
 MOC_DIR += temp
@@ -40,7 +40,6 @@
     dict \
     target \
     desktop \
-    uninstaller \
     mime \
     icon
 LIBS = -lSDL \
@@ -50,22 +49,19 @@
 QT += core \
     gui
 
-data.path = /usr/share/sounds
+data.path = $$PREFIX/share/sounds
 data.files = resource/sounds/*
-target.path = /usr/bin
-desktop.path = /usr/share/applications
+target.path = $$PREFIX/bin
+desktop.path = $$PREFIX/share/applications
 desktop.files = resource/desktop/textroom.desktop
-doc-icon.path = /usr/share/textroom
+doc-icon.path = $$PREFIX/share/textroom
 doc-icon.files = resource/images/textroom-doc.png
-mime.path = /usr/share/textroom
+mime.path = $$PREFIX/share/mime/packages
 mime.files = resource/desktop/textroom-txr-mime.xml
-uninstaller.path = /usr/bin
+uninstaller.path = $$PREFIX/bin
 uninstaller.files = resource/desktop/textroom-uninstall
-dict.path = /usr/share/myspell/dicts
+dict.path = $$PREFIX/share/myspell/dicts
 dict.files = resource/dict/*
-icon.path = /usr/share/pixmaps
+icon.path = $$PREFIX/share/pixmaps
 icon.files = resource/images/textroom.png
 
-unix:system(xdg-icon-resource install --context mimetypes --size 48 ./resource/images/textroom-doc.png application/x-txr)
-unix:system(xdg-mime install ./resource/desktop/textroom-txr-mime.xml)
-unix:system(xdg-mime default textroom.desktop application/x-txr)	
