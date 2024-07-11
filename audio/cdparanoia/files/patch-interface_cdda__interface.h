--- interface/cdda_interface.h.orig	2008-09-11 10:43:52 UTC
+++ interface/cdda_interface.h
@@ -21,6 +21,13 @@
 #include <sys/types.h>
 #include <signal.h>
 
+#ifdef __FreeBSD__
+#include <stdio.h>
+#include <camlib.h>
+
+#define ENOMEDIUM 12345
+#endif
+
 #define MAXTRK 100
 
 typedef struct TOC {	/* structure of table of contents */
@@ -49,13 +56,19 @@ typedef struct cdrom_drive{
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
