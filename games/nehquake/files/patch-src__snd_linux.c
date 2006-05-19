--- ./src/snd_linux.c.orig	Tue Nov  1 14:38:52 2005
+++ ./src/snd_linux.c	Tue May 16 17:36:22 2006
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
 
