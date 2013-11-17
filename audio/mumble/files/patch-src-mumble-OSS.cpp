--- src/mumble/OSS.cpp.orig	2013-08-03 14:01:25.000000000 +0200
+++ src/mumble/OSS.cpp	2013-08-03 14:12:51.000000000 +0200
@@ -153,7 +153,6 @@
 	qhOutput.insert(QString(), QLatin1String("Default OSS Device"));
 	qhDevices.insert(QString(), QLatin1String("/dev/dsp"));
 
-#if (SOUND_VERSION >= 0x040002)
 	int mixerfd = open("/dev/mixer", O_RDWR, 0);
 	if (mixerfd == -1) {
 		qWarning("OSSEnumerator: Failed to open /dev/mixer");
@@ -182,15 +181,14 @@
 		if (ainfo.caps & PCM_CAP_HIDDEN)
 			continue;
 
-		qhDevices.insert(handle, device);
+		qhDevices.insert(name, device);
 
 		if (ainfo.caps & PCM_CAP_INPUT)
-			qhInput.insert(handle, name);
+			qhInput.insert(name, name);
 		if (ainfo.caps & PCM_CAP_OUTPUT)
-			qhOutput.insert(handle, name);
+			qhOutput.insert(name, name);
 	}
 	close(mixerfd);
-#endif
 }
 
 OSSInput::OSSInput() {

