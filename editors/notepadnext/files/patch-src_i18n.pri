- translations are broken, see https://github.com/dail8859/NotepadNext/issues/147

--- src/i18n.pri.orig	2023-04-08 00:35:34 UTC
+++ src/i18n.pri
@@ -18,12 +18,12 @@
 
 CONFIG += lrelease embed_translations
 
-TRANSLATIONS = \
-    ../../i18n/NotepadNext_zh_CN.ts \
-    ../../i18n/NotepadNext_sv_SE.ts \
-    ../../i18n/NotepadNext_uk_UA.ts
+#TRANSLATIONS = \
+#    ../../i18n/NotepadNext_zh_CN.ts \
+#    ../../i18n/NotepadNext_sv_SE.ts \
+#    ../../i18n/NotepadNext_uk_UA.ts
 
-EXTRA_TRANSLATIONS = \
-    $$[QT_INSTALL_TRANSLATIONS]/qt_zh_CN.qm \
-    $$[QT_INSTALL_TRANSLATIONS]/qt_sv.qm \
-    $$[QT_INSTALL_TRANSLATIONS]/qt_uk.qm
+#EXTRA_TRANSLATIONS = \
+#    $$[QT_INSTALL_TRANSLATIONS]/qt_zh_CN.qm \
+#    $$[QT_INSTALL_TRANSLATIONS]/qt_sv.qm \
+#    $$[QT_INSTALL_TRANSLATIONS]/qt_uk.qm
