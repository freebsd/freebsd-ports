--- src/soundcard/sound.cxx.orig	Fri Jan 26 10:49:19 2007
+++ src/soundcard/sound.cxx	Mon Jan 29 21:51:41 2007
@@ -16,7 +16,9 @@
 	
 	try {
 		Open(O_RDONLY);
+#if 0
 		getVersion();
+#endif
 		getCapabilities();
 		getFormats();
 		Close();
@@ -80,7 +82,7 @@
 {
 	int sndparam;
 // Try to get ~100ms worth of samples per fragment
-	sndparam = (int)log2(sample_frequency * 0.1);
+	sndparam = (int)log2((unsigned int)(sample_frequency * 0.1));
 // double since we are using 16 bit samples
 	sndparam += 1;
 // Unlimited amount of buffers for RX, four for TX
@@ -122,7 +124,7 @@
 void cSound::getVersion()
 {
 	version = 0;
-	if (ioctl(device_fd, OSS_GETVERSION, &version) == -1) {
+	if (ioctl(device_fd, SOUND_VERSION, &version) == -1) {
 		version = -1;
 		throw SndException("OSS Version");
 	}
