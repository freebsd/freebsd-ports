Index: interface/cdda_interface.h
===================================================================
RCS file: /home/cvs/cdparanoia/interface/cdda_interface.h,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -r1.1.1.1 -r1.3
--- interface/cdda_interface.h	2003/01/05 09:46:26	1.1.1.1
+++ interface/cdda_interface.h	2003/01/06 21:26:23	1.3
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
@@ -46,14 +51,20 @@
 
   int opened; /* This struct may just represent a candidate for opening */
 
+#ifdef Linux
   char *cdda_device_name;
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
@@ -83,9 +94,13 @@
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
