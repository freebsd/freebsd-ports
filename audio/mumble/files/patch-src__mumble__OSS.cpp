--- src/mumble/OSS.cpp.orig	2019-08-30 01:01:56 UTC
+++ src/mumble/OSS.cpp
@@ -130,7 +130,6 @@ OSSEnumerator::OSSEnumerator() {
 	qhOutput.insert(QString(), QLatin1String("Default OSS Device"));
 	qhDevices.insert(QString(), QLatin1String("/dev/dsp"));
 
-#if (SOUND_VERSION >= 0x040002)
 	int mixerfd = open("/dev/mixer", O_RDWR, 0);
 	if (mixerfd == -1) {
 		qWarning("OSSEnumerator: Failed to open /dev/mixer");
@@ -159,15 +158,14 @@ OSSEnumerator::OSSEnumerator() {
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
@@ -198,20 +196,23 @@ void OSSInput::run() {
 	ival = AFMT_S16_NE;
 	if ((ioctl(fd, SNDCTL_DSP_SETFMT, &ival) == -1) || (ival != AFMT_S16_NE)) {
 		qWarning("OSSInput: Failed to set sound format");
-		goto out;
+		close(fd);
+		return;
 	}
 
 	ival = 1;
 	if ((ioctl(fd, SNDCTL_DSP_CHANNELS, &ival) == -1)) {
 		qWarning("OSSInput: Failed to set mono mode");
-		goto out;
+		close(fd);
+		return;
 	}
 	iMicChannels = ival;
 
 	ival = SAMPLE_RATE;
 	if (ioctl(fd, SNDCTL_DSP_SPEED, &ival) == -1) {
 		qWarning("OSSInput: Failed to set speed");
-		goto out;
+		close(fd);
+		return;
 	}
 	iMicFreq = ival;
 
@@ -235,8 +236,6 @@ void OSSInput::run() {
 	qWarning("OSSInput: Releasing.");
 	ioctl(fd, SNDCTL_DSP_RESET, NULL);
 
-out:
-	close(fd);
 }
 
 OSSOutput::OSSOutput() {
