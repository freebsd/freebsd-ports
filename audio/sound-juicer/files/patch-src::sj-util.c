--- src/sj-util.c.orig	Wed Jan  7 20:38:00 2004
+++ src/sj-util.c	Fri Jan 23 10:48:36 2004
@@ -120,6 +120,9 @@
     gtk_widget_destroy (dialog);
     goto done;
   }
+#ifdef __FreeBSD__
+  ioctl (fd, CDIOCALLOW);
+#endif
   result = ioctl (fd, CDROMEJECT);
   if (result == -1) {
     GtkWidget *dialog;
@@ -148,21 +151,33 @@
 tray_is_opened (const char *device)
 {
   int fd, status;
-  
+
+#if defined(__linux__)
   fd = open (device, O_RDONLY | O_NONBLOCK | O_EXCL);
   if (fd < 0) {
     return FALSE;
   }
-  
+
   status = ioctl (fd, CDROM_DRIVE_STATUS, CDSL_CURRENT);
+  close (fd);
   if (status < 0) {
-    close (fd);
     return FALSE;
   }
   
-  close (fd);
-  
   return status == CDS_TRAY_OPEN;
+#elif defined(__FreeBSD__)
+  struct ioc_toc_header h;
+
+  fd = open (device, O_RDONLY | O_NONBLOCK | O_EXCL);
+  if (fd < 0) {
+    return FALSE;
+  }
+
+  status = ioctl (fd, CDIOREADTOCHEADER, &h);
+  close (fd);
+
+  return status < 0;
+#endif
 }
 
 gboolean is_audio_cd (const char *device)
@@ -170,6 +185,10 @@
   CDMediaType type;
   int fd, status;
 
+  if (tray_is_opened (device)) {
+    return FALSE;
+  }
+
   type = guess_media_type (device);
   switch (type) {
     case CD_MEDIA_TYPE_CD:
@@ -189,15 +208,18 @@
     return FALSE;
   }
 
+#if defined(__linux__)
   status = ioctl (fd, CDROM_DISC_STATUS, CDSL_CURRENT);
+  close (fd);
   if (status < 0) {
-    close (fd);
     return FALSE;
   }
-
-  close (fd);
-
   return status == CDS_AUDIO;
+#elif defined (__FreeBSD__)
+  return TRUE;
+#else
+  return TRUE;
+#endif
 }
 
 /* Pass NULL to use g_free */
