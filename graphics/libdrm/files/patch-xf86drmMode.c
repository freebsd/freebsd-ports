--- xf86drmMode.c.orig	2017-01-28 01:15:16 UTC
+++ xf86drmMode.c
@@ -47,6 +47,7 @@
 #include <stdlib.h>
 #include <sys/ioctl.h>
 #ifdef HAVE_SYS_SYSCTL_H
+#include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
 #include <stdio.h>
