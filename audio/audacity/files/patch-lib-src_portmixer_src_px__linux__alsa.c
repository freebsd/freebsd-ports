--- lib-src/portmixer/src/px_linux_alsa.c.orig	2016-01-08 22:05:48 UTC
+++ lib-src/portmixer/src/px_linux_alsa.c
@@ -42,6 +42,7 @@
 
 #include "portaudio.h"
 #include "pa_unix_oss.h"
+#include <pa_linux_alsa.h>
 
 #include "portmixer.h"
 #include "px_mixer.h"
