- translations are broken, see https://github.com/dail8859/NotepadNext/issues/147

--- src/i18n.pri.orig	2022-05-27 20:06:21 UTC
+++ src/i18n.pri
@@ -18,11 +18,11 @@
 
 CONFIG += lrelease
 
-TRANSLATIONS = \
-    ../../i18n/NotepadNext.zh_CN.ts
+#TRANSLATIONS = \
+#    ../../i18n/NotepadNext.zh_CN.ts
 
-EXTRA_TRANSLATIONS = \
-    $$[QT_INSTALL_TRANSLATIONS]/qt_zh_CN.qm
+#EXTRA_TRANSLATIONS = \
+#    $$[QT_INSTALL_TRANSLATIONS]/qt_zh_CN.qm
 
 # Output folder for `.qm` files
-LRELEASE_DIR = $$OUT_PWD/i18n
+#LRELEASE_DIR = $$OUT_PWD/i18n
