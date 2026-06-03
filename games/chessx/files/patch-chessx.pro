--- chessx.pro.orig	2026-01-29 10:50:39 UTC
+++ chessx.pro
@@ -55,18 +55,26 @@ unix|!macx {
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
 
@@ -609,10 +617,10 @@ PRE_TARGETDEPS += compiler_TSQM_make_all
 PRE_TARGETDEPS += compiler_TSQM_make_all
 
 # Automatically run lupdate when building
-updateqm.commands = lupdate $$PWD/$$TARGET.pro && lrelease $$PWD/i18n/*.ts
+updateqm.commands = lupdate-qt5 $$PWD/$$TARGET.pro && lrelease $$PWD/i18n/*.ts
 QMAKE_EXTRA_TARGETS += updateqm
 
-update_translations.commands = lupdate $$PWD -ts $$TRANSLATIONS
+update_translations.commands = lupdate-qt5 $$PWD -ts $$TRANSLATIONS
 QMAKE_EXTRA_TARGETS += update_translations
 PRE_TARGETDEPS += update_translations  # Optional: Run before build
 
