--- tuneradio.c.orig	2003-10-31 05:53:39 UTC
+++ tuneradio.c
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
