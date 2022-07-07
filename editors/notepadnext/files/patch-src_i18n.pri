- translations are broken, see https://github.com/dail8859/NotepadNext/issues/147

--- src/i18n.pri.orig	2022-07-07 05:49:45 UTC
+++ src/i18n.pri
@@ -18,13 +18,13 @@
 
 CONFIG += lrelease
 
-TRANSLATIONS = \
-    ../../i18n/NotepadNext.zh_CN.ts \
-    ../../i18n/NotepadNext.sv_SE.ts
+#TRANSLATIONS = \
+#    ../../i18n/NotepadNext.zh_CN.ts \
+#    ../../i18n/NotepadNext.sv_SE.ts
 
-EXTRA_TRANSLATIONS = \
-    $$[QT_INSTALL_TRANSLATIONS]/qt_zh_CN.qm \
-    $$[QT_INSTALL_TRANSLATIONS]/qt_sv.qm
+#EXTRA_TRANSLATIONS = \
+#    $$[QT_INSTALL_TRANSLATIONS]/qt_zh_CN.qm \
+#    $$[QT_INSTALL_TRANSLATIONS]/qt_sv.qm
 
 # Output folder for `.qm` files
-LRELEASE_DIR = $$OUT_PWD/i18n
+#LRELEASE_DIR = $$OUT_PWD/i18n
