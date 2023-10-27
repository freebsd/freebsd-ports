--- audio/alsa_opl.cpp.orig	2023-10-25 18:59:21 UTC
+++ audio/alsa_opl.cpp
@@ -38,7 +38,7 @@
 
 #include <sys/ioctl.h>
 #include <alsa/asoundlib.h>
-#include <sound/asound_fm.h>
+#include <alsa/sound/asound_fm.h>
 
 namespace OPL {
 namespace ALSA {
