--- src/i18n.pri.orig	2023-10-20 04:05:44 UTC
+++ src/i18n.pri
@@ -18,16 +18,16 @@
 
 CONFIG += lrelease embed_translations
 
-TRANSLATIONS = \
-    ../../i18n/NotepadNext_zh_CN.ts \
-    ../../i18n/NotepadNext_zh_TW.ts \
-    ../../i18n/NotepadNext_sv_SE.ts \
-    ../../i18n/NotepadNext_uk_UA.ts \
-    ../../i18n/NotepadNext_tr_TR.ts
+#TRANSLATIONS = \
+#    ../../i18n/NotepadNext_zh_CN.ts \
+#    ../../i18n/NotepadNext_zh_TW.ts \
+#    ../../i18n/NotepadNext_sv_SE.ts \
+#    ../../i18n/NotepadNext_uk_UA.ts \
+#    ../../i18n/NotepadNext_tr_TR.ts
 
-EXTRA_TRANSLATIONS = \
-    $$[QT_INSTALL_TRANSLATIONS]/qt_zh_CN.qm \
-    $$[QT_INSTALL_TRANSLATIONS]/qt_zh_TW.qm \
-    $$[QT_INSTALL_TRANSLATIONS]/qt_sv.qm \
-    $$[QT_INSTALL_TRANSLATIONS]/qt_uk.qm \
-    $$[QT_INSTALL_TRANSLATIONS]/qt_tr.qm
+#EXTRA_TRANSLATIONS = \
+#    $$[QT_INSTALL_TRANSLATIONS]/qt_zh_CN.qm \
+#    $$[QT_INSTALL_TRANSLATIONS]/qt_zh_TW.qm \
+#    $$[QT_INSTALL_TRANSLATIONS]/qt_sv.qm \
+#    $$[QT_INSTALL_TRANSLATIONS]/qt_uk.qm \
+#    $$[QT_INSTALL_TRANSLATIONS]/qt_tr.qm
