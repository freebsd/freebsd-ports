Index: interface/common_interface.c
===================================================================
RCS file: /home/cvs/cdparanoia/interface/common_interface.c,v
retrieving revision 1.1.1.1
retrieving revision 1.5
diff -u -r1.1.1.1 -r1.5
--- interface/common_interface.c	2003/01/05 09:46:26	1.1.1.1
+++ interface/common_interface.c	2003/01/06 21:39:53	1.5
@@ -13,12 +13,19 @@
 #include "utils.h"
 #include "smallft.h"
 
+#ifdef Linux
 #include <linux/hdreg.h>
+#endif
 
 /* Test for presence of a cdrom by pinging with the 'CDROMVOLREAD' ioctl() */
 int ioctl_ping_cdrom(int fd){
+#ifdef Linux
   struct cdrom_volctrl volctl;
   if (ioctl(fd, CDROMVOLREAD, &volctl)) 
+#elif defined(__FreeBSD__)
+  struct ioc_vol volctl;
+  if (ioctl(fd, CDIOCGETVOL, &volctl))
+#endif
     return(1); /* failure */
 
   return(0);
@@ -26,6 +33,7 @@
 }
 
 
+#ifdef Linux
 /* Use the ioctl thingy above ping the cdrom; this will get model info */
 char *atapi_drive_info(int fd){
   /* Work around the fact that the struct grew without warning in
@@ -46,6 +54,7 @@
   free(id);
   return(ret);
 }
+#endif
 
 int data_bigendianp(cdrom_drive *d){
   float lsb_votes=0;
@@ -171,7 +180,9 @@
    knows the leasoud/leadin size. */
 
 int FixupTOC(cdrom_drive *d,int tracks){
+#ifdef Linux
   struct cdrom_multisession ms_str;
+#endif
   int j;
   
   /* First off, make sure the 'starting sector' is >=0 */
@@ -208,6 +219,8 @@
   /* For a scsi device, the ioctl must go to the specialized SCSI
      CDROM device, not the generic device. */
 
+  /* XXX */
+#ifdef Linux
   if (d->ioctl_fd != -1) {
     int result;
 
@@ -231,6 +244,7 @@
       return 1;
     }
   }
+#endif
   return 0;
 }
 
