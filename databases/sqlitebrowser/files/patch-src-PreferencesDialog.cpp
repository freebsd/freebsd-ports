--- src/PreferencesDialog.cpp.orig	2015-02-01 15:27:53.407669984 +0100
+++ src/PreferencesDialog.cpp	2015-02-01 15:30:51.885904399 +0100
@@ -266,9 +266,13 @@
 void PreferencesDialog::fillLanguageBox()
 {
     // Use the path relative to the main executable
+#ifdef Q_OS_FREEBSD
+    QDir translationsDir("%%DATADIR%%/translations",
+                         "sqlb_*.qm");
+#else
     QDir translationsDir(QCoreApplication::applicationDirPath() + "/translations",
                          "sqlb_*.qm");
-
+#endif
     // Add default language
     ui->languageComboBox->addItem("English (United States)", "en_US");
 
