--- audio_init.c.orig	2006-01-05 17:36:27 UTC
+++ audio_init.c
@@ -20,7 +20,7 @@
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 
 #include "rawrec.h"
 
