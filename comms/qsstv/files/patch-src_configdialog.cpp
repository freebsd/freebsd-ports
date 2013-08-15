--- src/configdialog.cpp.orig	2013-06-30 19:37:03.000000000 -0700
+++ src/configdialog.cpp	2013-06-30 19:38:19.000000000 -0700
@@ -100,14 +100,14 @@
 	txImagesPath=qSettings.value("txImagesPath",QString(getenv("HOME"))+"/").toString();
 	templatesPath=qSettings.value("templatesPath",QString(getenv("HOME"))+"/").toString();
 	audioPath=qSettings.value("audioPath",QString(getenv("HOME"))+"/").toString();
-	docPath  =qSettings.value("docPath",QString("/usr/share/doc/qsstv/")).toString();
+	docPath  =qSettings.value("docPath",QString("%%DOCSDIR%%")).toString();
 	defaultImageFormat=qSettings.value("defaultImageFormat","png").toString();
 	samplingrate=qSettings.value("samplingrate",11025).toInt();
 	rxClock=qSettings.value("rxclock",11025.).toDouble();
 	txClock=qSettings.value("txclock",11025.).toDouble();
 	inputAudioDevice=qSettings.value("inputAudioDevice","default").toString();
 	outputAudioDevice=qSettings.value("outputAudioDevice","default").toString();
-	serialPort=qSettings.value("serialPort","/dev/ttyS0").toString();
+	serialPort=qSettings.value("serialPort","/dev/ttyu0").toString();
   radioModel=qSettings.value("radioModel","dummy").toString();
   civAddress=qSettings.value("civAddress",0x70).toInt();
   baudrate=qSettings.value("baudrate",9600).toInt();
