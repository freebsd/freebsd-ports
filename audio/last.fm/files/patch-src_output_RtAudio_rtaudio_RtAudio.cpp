--- src/output/RtAudio/rtaudio/RtAudio.cpp.orig	2016-07-26 15:06:09 UTC
+++ src/output/RtAudio/rtaudio/RtAudio.cpp
@@ -42,7 +42,7 @@
 #include <QtGlobal>
 
 #ifdef Q_WS_X11
-    #define __LINUX_ALSA__
+    #define __LINUX_OSS__
 #endif
 #ifdef Q_WS_FREEBSD
     #define __LINUX_OSS__
@@ -57,6 +57,7 @@
 #include "RtAudio.h"
 #include <iostream>
 #include <stdio.h>
+#include <string.h>
 
 // Static variable definitions.
 const unsigned int RtApi::MAX_SAMPLE_RATES = 14;
