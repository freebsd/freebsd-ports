--- tuneradio.c.orig	Fri Oct 31 06:53:39 2003
+++ tuneradio.c	Mon Feb  9 21:40:26 2004
@@ -41,7 +41,12 @@
 #include <unistd.h>
 #include <sys/ioctl.h>
 #include <sys/types.h>
+#include <sys/param.h>
+#if __FreeBSD_version >= 502100
+#include <dev/bktr/ioctl_bt848.h>
+#else
 #include <machine/ioctl_bt848.h>
+#endif
 
 #define TRUE 1
 #define FALSE 0
