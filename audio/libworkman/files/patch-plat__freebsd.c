--- plat_freebsd.c.orig	1999-03-07 08:36:40 UTC
+++ plat_freebsd.c
@@ -30,7 +30,7 @@
  *
  */
 
-#if defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 
 static char freebsd_id[] = "$Id: plat_freebsd.c,v 1.8 1999/03/07 08:36:40 dirk Exp $";
 
@@ -49,7 +49,6 @@ static char freebsd_id[] = "$Id: plat_fr
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #include <sys/cdio.h>
-#include <sys/scsiio.h>
 
 #if defined(__NetBSD__)
 # define MSF_MINUTES 1
@@ -60,9 +59,6 @@ static char freebsd_id[] = "$Id: plat_fr
 #else
 # define LEFT_PORT 0
 # define RIGHT_PORT 1
-# if __FreeBSD_version < 300000
-#  include <scsi.h>
-# endif
 #endif
 
 #include "include/wm_struct.h"
