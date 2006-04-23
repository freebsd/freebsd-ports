--- src/backends/alc_backend_esd.c.orig	Sat Apr 22 21:06:15 2006
+++ src/backends/alc_backend_esd.c	Sat Apr 22 21:05:33 2006
@@ -15,6 +15,7 @@
 #include <string.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
+#include <sys/select.h>
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <sys/types.h>
