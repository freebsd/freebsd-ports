--- ./src/mumble/VoiceRecorderDialog.cpp.orig	2013-06-01 21:16:32.000000000 +0000
+++ ./src/mumble/VoiceRecorderDialog.cpp	2013-10-12 02:38:45.441221500 +0000
@@ -38,7 +38,7 @@
 #include "ServerHandler.h"
 #include "VoiceRecorder.h"
 
-VoiceRecorderDialog::VoiceRecorderDialog(QWidget *p = NULL) : QDialog(p), qtTimer(new QTimer(this)) {
+VoiceRecorderDialog::VoiceRecorderDialog(QWidget *p) : QDialog(p), qtTimer(new QTimer(this)) {
 	qtTimer->setObjectName(QLatin1String("qtTimer"));
 	qtTimer->setInterval(200);
 	setupUi(this);
