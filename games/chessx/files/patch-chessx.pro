--- chessx.pro.orig	2023-05-08 20:22:12 UTC
+++ chessx.pro
@@ -67,18 +67,26 @@ unix|!macx {
     BINDIR = $$PREFIX/bin
     DATADIR = $$PREFIX/share
 
-    INSTALLS += appdata desktop icons binfiles
+    INSTALLS += appdata desktop icons32 icons64 icons128 pixmaps binfiles
 
     appdata.files = unix/io.sourceforge.ChessX.metainfo.xml
     appdata.path = $$DATADIR/metainfo
+
     desktop.files = unix/chessx.desktop
     desktop.path = $$DATADIR/applications
 
-    icons.path = $$DATADIR/icons/hicolor
-    icons.commands = install -Dm644 data/images/chessx.png    $${icons.path}/128x128/apps/chessx.png; \
-                     install -Dm644 data/images/chessx-32.png $${icons.path}/32x32/apps/chessx.png; \
-                     install -Dm644 data/images/chessx-64.png $${icons.path}/64x64/apps/chessx.png;
+    icons32.files = data/images/chessx-32.png
+    icons32.path = $$DATADIR/icons/hicolor/32x32/apps
 
+    icons64.path = $$DATADIR/icons/hicolor/64x64/apps
+    icons64.files = data/images/chessx-64.png
+
+    icons128.path = $$DATADIR/icons/hicolor/128x128/apps
+    icons128.files = data/images/chessx.png
+
+    pixmaps.path = $$PREFIX/share/pixmaps
+    pixmaps.files = data/images/chessx.png
+
     binfiles.files = release/chessx
     binfiles.path = $$BINDIR
 }
@@ -532,6 +540,7 @@ win32 {
   INCLUDEPATH += $$[QT_INSTALL_HEADERS]/QtZlib
   win32-g++:LIBS += -lz
 }
+
 
 UI_DIR = src/generated
 MOC_DIR = src/generated
