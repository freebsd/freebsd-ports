--- hfkernel/mt63/sound.cc.orig	Sun Jul 30 11:01:27 2006
+++ hfkernel/mt63/sound.cc	Sun Jul 30 11:41:22 2006
@@ -30,6 +30,11 @@
 #include <sys/soundcard.h>
 #include <sys/ioctl.h>
 #endif
+#ifdef __FreeBSD__ 
+#include <unistd.h>
+#include <sys/soundcard.h>
+#include <sys/ioctl.h>
+#endif
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>
