--- sndserv/linux.c.orig	2003-12-08 22:44:54 UTC
+++ sndserv/linux.c
@@ -33,7 +33,7 @@
 #include <sys/ioctl.h>
 #include <errno.h>
 
-#include <linux/soundcard.h>
+#include <soundcard.h>
 
 #include "soundsrv.h"
 
