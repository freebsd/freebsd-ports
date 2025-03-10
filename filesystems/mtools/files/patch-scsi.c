--- scsi.c.orig	2018-12-02 16:23:26 UTC
+++ scsi.c
@@ -62,7 +62,7 @@
 #include <sys/scsicmd.h>
 #endif
 
-#if (defined(OS_freebsd)) && (__FreeBSD__ >= 2)
+#if (defined(OS_freebsd)) && (__FreeBSD__ >= 3)
 #include <camlib.h>
 #endif
 
@@ -82,7 +82,7 @@ int scsi_max_length(void)
 int scsi_open(const char *name, int flag UNUSEDP, int mode UNUSEDP,
 	      void **extra_data UNUSEDP)
 {
-#if (defined(OS_freebsd)) && (__FreeBSD__ >= 2)
+#if (defined(OS_freebsd)) && (__FreeBSD__ >= 3)
     struct cam_device *cam_dev;
     cam_dev = cam_open_device(name, O_RDWR);
     *extra_data = (void *) cam_dev;
@@ -245,7 +245,7 @@ int scsi_cmd(int fd, unsigned char *cdb, int cmdlen, s
         }
         
         return 0;
-#elif (defined OS_freebsd) && (__FreeBSD__ >= 2)
+#elif (defined OS_freebsd) && (__FreeBSD__ >= 3)
 #define MSG_SIMPLE_Q_TAG 0x20 /* O/O */
       union ccb *ccb;
       int flags;
