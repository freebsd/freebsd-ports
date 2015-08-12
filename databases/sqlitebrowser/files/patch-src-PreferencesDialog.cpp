--- src/PreferencesDialog.cpp.orig	2015-04-27 09:31:47 UTC
+++ src/PreferencesDialog.cpp
@@ -356,8 +356,15 @@ void PreferencesDialog::removeExtension(
 
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
 
