--- src/soundcard/sound.cxx.orig	Tue Dec 19 21:31:04 2006
+++ src/soundcard/sound.cxx	Wed Dec 20 18:46:00 2006
@@ -16,7 +16,9 @@
 	
 	try {
 		Open(O_RDONLY);
+#if 0
 		getVersion();
+#endif
 		getCapabilities();
 		getFormats();
 		Close();
@@ -78,7 +80,7 @@
 {
 	int sndparam;
 // Try to get ~100ms worth of samples per fragment
-	sndparam = (int)log2(sample_frequency * 0.1);
+	sndparam = (int)log2((unsigned int)(sample_frequency * 0.1));
 // double since we are using 16 bit samples
 	sndparam += 1;
 // Unlimited amount of buffers for RX, four for TX
@@ -120,7 +122,7 @@
 void cSound::getVersion()
 {
 	version = 0;
-	if (ioctl(device_fd, OSS_GETVERSION, &version) == -1) {
+	if (ioctl(device_fd, SOUND_VERSION, &version) == -1) {
 		version = -1;
 		throw SndException("OSS Version");
 	}
