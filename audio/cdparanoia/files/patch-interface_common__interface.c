Index: interface/common_interface.c
===================================================================
RCS file: /home/cvs/cdparanoia/interface/common_interface.c,v
retrieving revision 1.1.1.1
retrieving revision 1.5
--- interface/common_interface.c.orig	2008-08-21 16:08:54 UTC
+++ interface/common_interface.c
@@ -13,15 +13,25 @@
 #include "utils.h"
 #include "smallft.h"
 
+#ifdef Linux
 #include <linux/hdreg.h>
+#elif defined(__FreeBSD__)
+#include <sys/cdio.h>
+#endif
 
 /* Test for presence of a cdrom by pinging with the 'CDROMVOLREAD' ioctl() */
 /* Also test using CDROM_GET_CAPABILITY (if available) as some newer DVDROMs will
    reject CDROMVOLREAD ioctl for god-knows-what reason */
 int ioctl_ping_cdrom(int fd){
+#ifdef Linux
   struct cdrom_volctrl volctl;
   if (ioctl(fd, CDROMVOLREAD, &volctl) &&
       ioctl(fd, CDROM_GET_CAPABILITY, NULL)<0)
+#elif defined(__FreeBSD__)
+  struct ioc_vol volctl;
+  if (ioctl(fd, CDIOCGETVOL, &volctl) &&
+     (ioctl(fd, CDIOCCAPABILITY, NULL)<0))
+#endif
     return(1); /* failure */
 
   return(0);
@@ -29,6 +39,7 @@ int ioctl_ping_cdrom(int fd){
 }
 
 
+#ifdef Linux
 /* Use the ioctl thingy above ping the cdrom; this will get model info */
 char *atapi_drive_info(int fd){
   /* Work around the fact that the struct grew without warning in
@@ -49,6 +60,7 @@ char *atapi_drive_info(int fd){
   free(id);
   return(ret);
 }
+#endif
 
 int data_bigendianp(cdrom_drive *d){
   float lsb_votes=0;
@@ -174,7 +186,9 @@ int data_bigendianp(cdrom_drive *d){
    knows the leadout/leadin size. */
 
 int FixupTOC(cdrom_drive *d,int tracks){
+#ifdef Linux
   struct cdrom_multisession ms_str;
+#endif
   int j;
   
   /* First off, make sure the 'starting sector' is >=0 */
@@ -211,6 +225,8 @@ int FixupTOC(cdrom_drive *d,int tracks){
   /* For a scsi device, the ioctl must go to the specialized SCSI
      CDROM device, not the generic device. */
 
+  /* XXX */
+#ifdef Linux
   if (d->ioctl_fd != -1) {
     int result;
 
@@ -235,6 +251,16 @@ int FixupTOC(cdrom_drive *d,int tracks){
       return 1;
     }
   }
+#elif defined(__FreeBSD__)
+    for (j = tracks-1; j >= 0; j--) {
+      if (j > 0 && !IS_AUDIO(d,j) && IS_AUDIO(d,j-1)) {
+        if ((d->disc_toc[j].dwStartSector > d->disc_toc[j].dwStartSector - 11400) &&
+            (d->disc_toc[j].dwStartSector - 11400 > d->disc_toc[j-1].dwStartSector))
+          d->disc_toc[j].dwStartSector = d->disc_toc[j].dwStartSector - 11400;
+        break;
+      }
+    }
+#endif
   return 0;
 }
 
