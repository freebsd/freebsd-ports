Index: interface/low_interface.h
===================================================================
RCS file: /home/cvs/cdparanoia/interface/low_interface.h,v
retrieving revision 1.1.1.1
retrieving revision 1.3
--- interface/low_interface.h.orig	2008-09-11 10:43:52 UTC
+++ interface/low_interface.h
@@ -26,6 +26,8 @@
 #include <sys/time.h>
 #include <sys/types.h>
 
+#ifdef Linux
+
 #include <linux/major.h>
 #include <linux/version.h>
 
@@ -54,6 +56,17 @@
 #include <linux/cdrom.h>
 #include <linux/major.h>
 
+#elif defined(__FreeBSD__)
+
+#include <sys/cdio.h>
+#include <sys/cdrio.h>
+
+#include <cam/scsi/scsi_message.h>
+#include <cam/scsi/scsi_sg.h>
+#include <camlib.h>
+
+#endif
+
 #include "cdda_interface.h"
 
 #ifndef SG_EMULATED_HOST
@@ -107,10 +120,17 @@ struct cdda_private_data {
 #define MAX_RETRIES 8
 #define MAX_BIG_BUFF_SIZE 65536
 #define MIN_BIG_BUFF_SIZE 4096
+
+#ifdef Linux
 #define SG_OFF sizeof(struct sg_header)
+#else
+#define SG_OFF (0)
+#endif
 
 extern int  cooked_init_drive (cdrom_drive *d);
+#ifdef Linux
 extern unsigned char *scsi_inquiry (cdrom_drive *d);
+#endif
 extern int  scsi_init_drive (cdrom_drive *d);
 #ifdef CDDA_TEST
 extern int  test_init_drive (cdrom_drive *d);
