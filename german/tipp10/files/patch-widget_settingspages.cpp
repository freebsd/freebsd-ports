--- widget/settingspages.cpp.orig	2013-10-30 15:20:29.120118000 +0000
+++ widget/settingspages.cpp
@@ -501,7 +501,7 @@ void DatabasePage::writeSettings() {
 	QSettings settings;
 	#endif
 	settings.beginGroup("database");
-	settings.setValue("pathpro", lineDatabasePath->text() + "/" + QString::QString(APP_USER_DB));
+	settings.setValue("pathpro", lineDatabasePath->text() + "/" + QString(APP_USER_DB));
 	settings.endGroup();
 }
 
