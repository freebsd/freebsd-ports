--- src/src.pro.orig	2023-09-13 06:27:01 UTC
+++ src/src.pro
@@ -61,7 +61,7 @@ QT += xml network widgets printsupport
 
 QT += xml network widgets printsupport
 
-linux-g++*:{
+unix:{
     LIBS += -lX11
 }
 
@@ -130,3 +130,13 @@ greaterThan(QT_MAJOR_VERSION, 4) {
     SOURCES += viewwindow_webkit.cpp dataprovider_qwebkit.cpp
     HEADERS += dataprovider_qwebkit.h viewwindow_webkit.h
 }
+# Define installation target for the binary
+target.path = $$PREFIX/bin
+# ... and for the icon
+icons.files = ../packages/kchmviewer.png
+icons.path = $$PREFIX/share/pixmaps
+# ... and the desktop file
+desktop.files = ../packages/kchmviewer.desktop
+desktop.path = $$PREFIX/share/applications
+
+INSTALLS += desktop icons target
