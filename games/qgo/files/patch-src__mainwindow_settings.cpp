--- src/mainwindow_settings.cpp.orig
+++ src/mainwindow_settings.cpp
@@ -269,7 +269,13 @@
 	QVariant var;
 	
 	ui.comboBox_language->setCurrentIndex (settings.value("LANGUAGE").toInt());
-	ui.LineEdit_computer->setText(settings.value("COMPUTER_PATH").toString());
+        QString computer_path = settings.value("COMPUTER_PATH").toString();
+        qDebug() << "COMPUTER_PATH" << computer_path;
+        if (computer_path == "") {
+                computer_path = "%%LOCALBASE%%/bin/gnugo";
+                settings.setValue("COMPUTER_PATH", computer_path);
+        }
+	ui.LineEdit_computer->setText(computer_path);
 	if(settings.value("COMPUTER_PLAYS_WHITE").toBool())
 		ui.computerPlaysWhite->setChecked(TRUE);
 	else
