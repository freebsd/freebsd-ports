--- src_sound/dsp_mixxer.c.orig	Sat May 10 00:11:13 2003
+++ src_sound/dsp_mixxer.c	Sat May 10 00:11:16 2003
@@ -19,10 +19,8 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
-#ifdef Linux
+#if defined(Linux) || defined(FreeBSD)
  #include <sys/soundcard.h>
-#elif FreeBSD
- #include <machine/soundcard.h>
 #endif
 #include "funktracker_defs.h"
 #include "funktracker.h"
