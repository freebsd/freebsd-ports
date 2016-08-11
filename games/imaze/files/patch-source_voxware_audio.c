--- source/voxware_audio.c.orig	2001-12-10 00:47:46 UTC
+++ source/voxware_audio.c
@@ -50,7 +50,7 @@
 #ifdef linux
 #include <linux/soundcard.h>
 #else
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #endif
 
 #include "argv.h"
