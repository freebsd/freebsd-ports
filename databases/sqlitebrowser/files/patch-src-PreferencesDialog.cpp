--- src/PreferencesDialog.cpp.orig	2015-05-09 08:19:49.920343024 +0200
+++ src/PreferencesDialog.cpp	2015-05-09 08:20:57.913337598 +0200
@@ -356,8 +356,15 @@
 
 void PreferencesDialog::fillLanguageBox()
 {
-    QDir translationsDir(QCoreApplication::applicationDirPath() + "/translations",
+
+#ifdef Q_OS_FREEBSD
+    QDir translationsDir("%%DATADIR%%/translations",
                          "sqlb_*.qm");
+#else
+     QDir translationsDir(QCoreApplication::applicationDirPath() + "/translations",
+                          "sqlb_*.qm");
+
+#endif
 
     QLocale systemLocale = QLocale::system();
 
