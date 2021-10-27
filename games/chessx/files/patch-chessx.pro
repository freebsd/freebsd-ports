--- chessx.pro.orig	2021-09-17 10:33:08 UTC
+++ chessx.pro
@@ -534,24 +534,30 @@ lc0 {
   QMAKE_BUNDLE_DATA += LC0_ENGINE_LIB
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
 RESOURCES = \
   resources.qrc translations.qrc
 
-TRANSLATIONS = i18n/chessx_de.ts
-
-#\
-#        i18n/chessx_da.ts \
-#        i18n/chessx_fr.ts \
-#        i18n/chessx_it.ts \
-#        i18n/chessx_cz.ts \
-#        i18n/chessx_ru.ts \
-#        i18n/chessx_es.ts
-
-#   i18n/chessx_nl.ts \
-#   i18n/chessx_pl.ts \
-#   i18n/chessx_pt_BR.ts \
-#   i18n/chessx_ro.ts \
-#   i18n/chessx_zh.ts
+TRANSLATIONS = i18n/chessx_de.ts \
+        i18n/chessx_da.ts \
+        i18n/chessx_fr.ts \
+        i18n/chessx_it.ts \
+        i18n/chessx_cz.ts \
+        i18n/chessx_ru.ts \
+        i18n/chessx_es.ts \
+        i18n/chessx_nl.ts \
+        i18n/chessx_pl.ts \
+        i18n/chessx_pt_BR.ts \
+        i18n/chessx_ro.ts \
+        i18n/chessx_zh.ts
 
 isEmpty(QMAKE_LRELEASE) {
   win32:QMAKE_LRELEASE = $$[QT_INSTALL_BINS]\\lrelease.exe
