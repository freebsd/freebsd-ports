--- ./engine/unix/linux_snd.c.orig	Sat Dec 16 17:32:42 2006
+++ ./engine/unix/linux_snd.c	Mon Apr 16 23:59:59 2007
@@ -32,9 +32,8 @@
 #include <sys/wait.h>
 #ifdef __linux__ // rb0101023 - guard this
 #include <linux/soundcard.h>
-#endif
-#ifdef __FreeBSD__ // rb0101023 - added
-#include <sys/soundcard.h>
+#else
+#include <sys/soundcard.h> // rb0101023 - added
 #endif
 #include <stdio.h>
 
