--- plat_freebsd.c.orig	1999-03-07 08:36:40 UTC
+++ plat_freebsd.c
@@ -49,7 +49,6 @@ static char freebsd_id[] = "$Id: plat_fr
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #include <sys/cdio.h>
-#include <sys/scsiio.h>
 
 #if defined(__NetBSD__)
 # define MSF_MINUTES 1
