--- src/sj-util.c.orig	Tue Feb  8 14:06:57 2005
+++ src/sj-util.c	Tue Feb  8 14:25:03 2005
@@ -157,6 +157,15 @@
   if (fd < 0) {
     return FALSE;
   }
+#if defined(__FreeBSD__)
+  status = FALSE;
+
+  ioctl (fd, CDIOCCLOSE);
+
+  close (fd);
+
+  return status;
+#else
   
   status = ioctl (fd, CDROM_DRIVE_STATUS, CDSL_CURRENT);
   if (status < 0) {
@@ -167,6 +176,7 @@
   close (fd);
   
   return status == CDS_TRAY_OPEN;
+#endif
 }
 
 gboolean is_audio_cd (const char *device)
@@ -191,7 +201,7 @@
     default:
       return FALSE;
   }
-
+/*
   fd = open (device, O_RDONLY | O_NONBLOCK | O_EXCL);
   if (fd <0) {
     return FALSE;
@@ -206,6 +216,7 @@
   close (fd);
 
   return status == CDS_AUDIO;
+  */
 }
 
 /* Pass NULL to use g_free */
