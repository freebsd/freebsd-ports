--- configdialog.cpp.orig	2008-03-05 09:37:46.000000000 -0500
+++ configdialog.cpp	2008-03-05 09:45:55.000000000 -0500
@@ -104,7 +104,7 @@
 void configDialog::readSettings()
 {
 	QSettings qSettings(QSettings::Ini);
-	docPath  =qSettings.readEntry(APP_KEY + "docPath",QString("/usr/share/doc/packages/qsstv/"));
+	docPath  =qSettings.readEntry(APP_KEY + "docPath",QString("%%DOCSDIR%%"));
 	audioPath=qSettings.readEntry(APP_KEY + "audioPath",QString(getenv("HOME"))+"/");
 	rxImagePath=qSettings.readEntry(APP_KEY + "rxImagePath",QString(getenv("HOME"))+"/");
 	templatePath=qSettings.readEntry(APP_KEY + "templatePath",QString(getenv("HOME"))+"/");
@@ -115,7 +115,7 @@
 	rxClock=qSettings.readDoubleEntry(APP_KEY + "rxClock",11025);
 	txClock=qSettings.readDoubleEntry(APP_KEY + "txClock",11025);
 	audioDevice=qSettings.readEntry(APP_KEY + "audioDevice","/dev/dsp");
-	serialPort=qSettings.readEntry(APP_KEY + "serialPort","/dev/ttyS0");
+	serialPort=qSettings.readEntry(APP_KEY + "serialPort","/dev/ttyd0");
 	callsign=qSettings.readEntry(APP_KEY + "callsign","NOCALL");
 	qth=qSettings.readEntry(APP_KEY + "qth","NOWHERE");
 	lastname=qSettings.readEntry(APP_KEY + "lastname","NONAME");
