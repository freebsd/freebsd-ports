--- src/PreferencesDialog.cpp.orig	2016-08-24 11:00:01 UTC
+++ src/PreferencesDialog.cpp
@@ -465,8 +465,13 @@ void PreferencesDialog::removeExtension(
 
 void PreferencesDialog::fillLanguageBox()
 {
+#ifdef Q_OS_FREEBSD
+    QDir translationsDir("%%DATADIR%%/translations",
+                         "sqlb_*.qm");
+#else
     QDir translationsDir(QCoreApplication::applicationDirPath() + "/translations",
                          "sqlb_*.qm");
+#endif
 
     QLocale systemLocale = QLocale::system();
 
