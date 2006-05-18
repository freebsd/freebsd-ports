--- ./src/snd_linux.c.orig	Thu Nov  3 16:19:53 2005
+++ ./src/snd_linux.c	Tue May 16 14:33:39 2006
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
 
