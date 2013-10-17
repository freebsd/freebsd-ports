--- plat_freebsd.c.orig	Thu Jan 27 12:17:46 2000
+++ plat_freebsd.c	Thu Jan 27 12:18:15 2000
@@ -49,7 +49,6 @@
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #include <sys/cdio.h>
-#include <sys/scsiio.h>
 
 #if defined(__NetBSD__)
 # define MSF_MINUTES 1
