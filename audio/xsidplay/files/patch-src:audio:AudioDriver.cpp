--- src/audio/AudioDriver.cpp	Thu Nov 29 19:15:31 2001
+++ src/audio/AudioDriver.cpp.new	Tue Jan  8 21:52:35 2002
@@ -43,11 +43,28 @@
 #include "AudioDriver.h"
 
 #if defined(HAVE_NETBSD)
-const char *AudioDriver::AUDIODEVICE[] = { "/dev/audio" };
-#else
+const char *AudioDriver::AUDIODEVICE[] = { "/dev/audio", "" };
+#elif defined(HAVE_FREEBSD)
+const char *AudioDriver::AUDIODEVICE[] = {
+  "/dev/dsp",
+  "/dev/audio",
+  "/dev/dsp0",
+  "/dev/audio0",
+  "/dev/dsp0.0",
+  "/dev/dsp0.1",
+  "/dev/dsp0.2",
+  "/dev/dsp0.3",
+  "/dev/audio0.0",
+  "/dev/audio0.1",
+  "/dev/audio0.2",
+  "/dev/audio0.3",
+  ""
+};
+#elif defined(HAVE_LINUX)
 const char *AudioDriver::AUDIODEVICE[] = {
   "/dev/dsp",
   "/dev/sound/dsp",
+  ""
 };
 #endif
 
