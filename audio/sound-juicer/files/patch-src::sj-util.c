--- src/sj-util.c.orig	Tue Jun 15 19:14:09 2004
+++ src/sj-util.c	Tue Jun 15 19:29:16 2004
@@ -122,6 +122,9 @@
     gtk_widget_destroy (dialog);
     goto done;
   }
+#ifdef __FreeBSD__
+  ioctl (fd, CDIOCALLOW);
+#endif
   result = ioctl (fd, CDROMEJECT);
   if (result == -1) {
     GtkWidget *dialog;
@@ -151,20 +154,32 @@
 {
   int fd, status;
   
+#if defined(__linux__)
   fd = open (device, O_RDONLY | O_NONBLOCK | O_EXCL);
   if (fd < 0) {
     return FALSE;
   }
   
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
@@ -191,15 +210,19 @@
     return FALSE;
   }
 
+#if defined(__linux__)
   status = ioctl (fd, CDROM_DISC_STATUS, CDSL_CURRENT);
+  close (fd);
   if (status < 0) {
-    close (fd);
     return FALSE;
   }
 
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
