--- ./source/snd_linux.c.orig	Mon Dec 25 17:07:02 2006
+++ ./source/snd_linux.c	Mon Dec 25 17:07:03 2006
@@ -27,6 +27,8 @@
 #include <sys/wait.h>
 #ifdef __linux__
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
 #endif
 #include <stdio.h>
 #include <errno.h>
