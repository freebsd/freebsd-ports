--- sndserv/linux.c.orig	Thu Jan 10 19:06:58 2002
+++ sndserv/linux.c	Thu Jan 10 19:07:06 2002
@@ -32,7 +32,7 @@
 #include <unistd.h>
 #include <sys/ioctl.h>
 
-#include <linux/soundcard.h>
+#include <soundcard.h>
 
 #include "soundsrv.h"
 
