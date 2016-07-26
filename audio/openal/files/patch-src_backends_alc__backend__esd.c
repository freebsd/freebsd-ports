--- src/backends/alc_backend_esd.c.orig	2006-01-12 18:12:11 UTC
+++ src/backends/alc_backend_esd.c
@@ -15,6 +15,7 @@
 #include <string.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
+#include <sys/select.h>
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <sys/types.h>
