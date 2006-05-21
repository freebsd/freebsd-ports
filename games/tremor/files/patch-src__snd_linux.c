--- ./src/snd_linux.c.orig	Mon Oct 31 20:29:19 2005
+++ ./src/snd_linux.c	Tue May 16 14:59:52 2006
@@ -25,7 +25,11 @@
 #include <sys/mman.h>
 #include <sys/shm.h>
 #include <sys/wait.h>
+#ifdef __linux__
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 #include <stdio.h>
 #include "quakedef.h"
 
