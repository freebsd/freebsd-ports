--- ./src/mumble/OSS.cpp.orig	2013-06-01 21:16:31.000000000 +0000
+++ ./src/mumble/OSS.cpp	2013-10-12 02:38:45.443221514 +0000
@@ -221,20 +221,23 @@
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
 
@@ -258,8 +261,6 @@
 	qWarning("OSSInput: Releasing.");
 	ioctl(fd, SNDCTL_DSP_RESET, NULL);
 
-out:
-	close(fd);
 }
 
 OSSOutput::OSSOutput() {
