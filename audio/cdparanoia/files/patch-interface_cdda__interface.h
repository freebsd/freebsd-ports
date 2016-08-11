--- interface/cdda_interface.h.orig	2001-03-24 01:15:46 UTC
+++ interface/cdda_interface.h
@@ -21,6 +21,11 @@
 #include <sys/types.h>
 #include <signal.h>
 
+#ifdef __FreeBSD__
+#include <stdio.h>
+#include <camlib.h>
+#endif
+
 #define MAXTRK 100
 
 typedef struct TOC {	/* structure of table of contents */
@@ -47,13 +52,19 @@ typedef struct cdrom_drive{
   int opened; /* This struct may just represent a candidate for opening */
 
   char *cdda_device_name;
+#ifdef Linux
   char *ioctl_device_name;
 
   int cdda_fd;
-  int ioctl_fd;
 
-  char *drive_model;
   int drive_type;
+#elif defined(__FreeBSD__)
+  struct cam_device *dev;
+  union ccb *ccb;
+#endif
+
+  int ioctl_fd;
+  char *drive_model;
   int interface;
   int bigendianp;
   int nsectors;
@@ -83,9 +94,13 @@ typedef struct cdrom_drive{
   int is_mmc;
 
   /* SCSI command buffer and offset pointers */
+#ifdef Linux
   unsigned char *sg;
   unsigned char *sg_buffer;
   unsigned char inqbytes[4];
+#elif defined(__FreeBSD__)
+  unsigned char *sg_buffer;
+#endif
 
   /* Scsi parameters and state */
   unsigned char density;
