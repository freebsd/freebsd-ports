--- src/soundcard/sound.cxx.orig	2018-12-06 14:41:46 UTC
+++ src/soundcard/sound.cxx
@@ -651,7 +651,27 @@ int SoundOSS::Open(int md, int freq)
 			oflags = oflags | O_CLOEXEC;
 #	   endif
 
+#ifdef __FreeBSD__
+/*
+ * In FreeBSD sound devices e.g. /dev/dsp0.0 can only be open once
+ * whereas /dev/dsp0 can be open multiple times. fldigi tries
+ * to open /dev/dsp0.0 multiple times which fails. Also see man 4 sound.
+ * "For specific sound card access, please instead use /dev/dsp or /dev/dsp%d"
+ * This is a hack. XXX - db VA3DB
+ */
+		char *fixed_name;
+		char *p;
+		/* Look for a '.' if found, blow it away */
+		fixed_name = strdup(device.c_str());
+		p = fixed_name;
+		while (*p++)
+			if(*p == '.')
+				*p = '\0';
+		device_fd = fl_open(fixed_name, oflags, 0);
+		free(fixed_name);
+#else
 		device_fd = fl_open(device.c_str(), oflags, 0);
+#endif
 		if (device_fd == -1)
 			throw SndException(errno);
 
@@ -677,12 +697,11 @@ void SoundOSS::Close(unsigned dir)
 void SoundOSS::getVersion()
 {
 	version = 0;
-#ifndef __FreeBSD__
+
 	if (ioctl(device_fd, OSS_GETVERSION, &version) == -1) {
 		version = -1;
 		throw SndException("OSS Version");
 	}
-#endif
 }
 
 void SoundOSS::getCapabilities()
