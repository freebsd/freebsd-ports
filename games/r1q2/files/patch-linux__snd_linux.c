--- ./linux/snd_linux.c.orig	Wed May 17 22:21:33 2006
+++ ./linux/snd_linux.c	Wed May 17 22:28:57 2006
@@ -8,8 +8,7 @@
 #include <sys/wait.h>
 #if defined (__linux__)
 #include <linux/soundcard.h>
-#endif
-#if defined (__FreeBSD__)
+#else
 #include <sys/soundcard.h>
 #endif
 #include <stdio.h>
