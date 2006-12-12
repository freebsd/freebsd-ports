--- gnome-cd/gst-cdrom.c.orig	Tue Dec 12 00:18:40 2006
+++ gnome-cd/gst-cdrom.c	Tue Dec 12 00:23:17 2006
@@ -41,13 +41,17 @@
 #endif
 
 #if defined(__FreeBSD__)
-# define GST_CDROM_IOCTL_CDCAPABILITY_REQUEST  CDIOCCAPABILITY
+# define GST_CDROM_IOCTL_CDCAPABILITY_REQUEST  CDIOCGETVOL
+struct ioc_vol vol_value;
+# define GST_CDROM_IOCTL_CDCAPABILITY_REQUEST_ADDR &vol_value
 # define GST_CDROM_IOCTL_EJECT_REQUEST         CDIOCEJECT
 #elif defined(__NetBSD__) || defined(__OpenBSD__)
 # define GST_CDROM_IOCTL_CDCAPABILITY_REQUEST  CDIOCGETVOL
+# define GST_CDROM_IOCTL_CDCAPABILITY_REQUEST_ADDR 0
 # define GST_CDROM_IOCTL_EJECT_REQUEST         CDIOCEJECT
 #else
 # define GST_CDROM_IOCTL_CDCAPABILITY_REQUEST  CDROM_GET_CAPABILITY
+# define GST_CDROM_IOCTL_CDCAPABILITY_REQUEST_ADDR 0
 # define GST_CDROM_IOCTL_EJECT_REQUEST         CDROMEJECT
 #endif
 
@@ -184,7 +188,7 @@ gst_cdrom_is_cdrom_device (GnomeCDRom * 
 
     fd = open (device, O_RDONLY | O_NONBLOCK);
     if (fd >= 0) {
-      if (ioctl (fd, GST_CDROM_IOCTL_CDCAPABILITY_REQUEST, 0) >= 0) {
+      if (ioctl (fd, GST_CDROM_IOCTL_CDCAPABILITY_REQUEST, GST_CDROM_IOCTL_CDCAPABILITY_REQUEST_ADDR) >= 0) {
         res = TRUE;
       } else {
         GST_DEBUG ("ioctl() failed: %s", g_strerror (errno));
