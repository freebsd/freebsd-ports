Index: interface/low_interface.h
===================================================================
RCS file: /home/cvs/cdparanoia/interface/low_interface.h,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -r1.1.1.1 -r1.3
--- interface/low_interface.h	2003/01/05 09:46:26	1.1.1.1
+++ interface/low_interface.h	2003/01/06 21:26:23	1.3
@@ -25,6 +25,8 @@
 #include <sys/time.h>
 #include <sys/types.h>
 
+#ifdef Linux
+
 #include <linux/major.h>
 #include <linux/version.h>
 
@@ -48,12 +50,27 @@
 #include <linux/cdrom.h>
 #include <linux/major.h>
 
+#elif defined(__FreeBSD__)
+
+#include <sys/cdio.h>
+#include <sys/cdrio.h>
+
+#include <cam/scsi/scsi_message.h>
+#include <camlib.h>
+
+#endif
+
 #include "cdda_interface.h"
 
 #define MAX_RETRIES 8
 #define MAX_BIG_BUFF_SIZE 65536
 #define MIN_BIG_BUFF_SIZE 4096
+
+#ifdef Linux
 #define SG_OFF sizeof(struct sg_header)
+#else
+#define SG_OFF (0)
+#endif
 
 #ifndef SG_EMULATED_HOST
 /* old kernel version; the check for the ioctl is still runtime, this
@@ -64,7 +81,9 @@
 #endif
 
 extern int  cooked_init_drive (cdrom_drive *d);
+#ifdef Linux
 extern unsigned char *scsi_inquiry (cdrom_drive *d);
+#endif
 extern int  scsi_init_drive (cdrom_drive *d);
 #ifdef CDDA_TEST
 extern int  test_init_drive (cdrom_drive *d);
