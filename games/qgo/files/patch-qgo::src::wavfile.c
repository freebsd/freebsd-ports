--- qgo/src/wavfile.c.orig	Tue Jun 24 06:57:08 2003
+++ qgo/src/wavfile.c	Mon Nov  3 00:49:30 2003
@@ -53,7 +53,6 @@
 #include <unistd.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <malloc.h>
 #include <string.h>
 #include <memory.h>
 #include <signal.h>
@@ -61,7 +60,7 @@
 #include <sys/ipc.h>
 #include <sys/ioctl.h>
 #include <assert.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 
 
 // stop
