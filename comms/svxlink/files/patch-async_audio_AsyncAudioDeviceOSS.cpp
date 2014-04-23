--- async/audio/AsyncAudioDeviceOSS.cpp.orig	2014-04-09 22:38:17.000000000 -0700
+++ async/audio/AsyncAudioDeviceOSS.cpp	2014-04-09 22:38:29.000000000 -0700
@@ -41,6 +41,7 @@
 #include <sys/soundcard.h>
 #include <sys/ioctl.h>
 #include <unistd.h>
+#include <stdlib.h>
 
 #include <cassert>
 #include <cstring>
