--- audio/drivers/alsa.c.orig	2025-11-20 00:17:08 UTC
+++ audio/drivers/alsa.c
@@ -22,7 +22,7 @@
 
 #include <alsa/asoundlib.h>
 #include <alsa/pcm.h>
-#include <asm-generic/errno.h>
+#include <errno.h>
 
 #include "../audio_driver.h"
 #include "../common/alsa.h"
