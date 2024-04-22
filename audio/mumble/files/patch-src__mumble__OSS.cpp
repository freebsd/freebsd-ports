--- src/mumble/OSS.cpp.orig	2024-03-03 17:26:27 UTC
+++ src/mumble/OSS.cpp
@@ -128,7 +128,6 @@ OSSEnumerator::OSSEnumerator() {
 	qhOutput.insert(QString(), QLatin1String("Default OSS Device"));
 	qhDevices.insert(QString(), QLatin1String("/dev/dsp"));
 
-#if (SOUND_VERSION >= 0x040002)
 	int mixerfd = open("/dev/mixer", O_RDWR, 0);
 	if (mixerfd == -1) {
 		qWarning("OSSEnumerator: Failed to open /dev/mixer");
@@ -157,15 +156,14 @@ OSSEnumerator::OSSEnumerator() {
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
@@ -212,12 +210,14 @@ void OSSInput::run() {
 	ival = AFMT_S16_NE;
 	if ((ioctl(fd, SNDCTL_DSP_SETFMT, &ival) == -1) || (ival != AFMT_S16_NE)) {
 		qWarning("OSSInput: Failed to set sound format");
+		close(fd);
 		return;
 	}
 
 	ival = 1;
 	if ((ioctl(fd, SNDCTL_DSP_CHANNELS, &ival) == -1)) {
 		qWarning("OSSInput: Failed to set mono mode");
+		close(fd);
 		return;
 	}
 	iMicChannels = static_cast< unsigned int >(ival);
@@ -225,6 +225,7 @@ void OSSInput::run() {
 	ival = SAMPLE_RATE;
 	if (ioctl(fd, SNDCTL_DSP_SPEED, &ival) == -1) {
 		qWarning("OSSInput: Failed to set speed");
+		close(fd);
 		return;
 	}
 	iMicFreq = static_cast< unsigned int >(ival);
