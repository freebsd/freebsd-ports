--- kernel/OS/FreeBSD/os_freebsd.c.orig	2009-01-04 00:05:36.000000000 -0500
+++ kernel/OS/FreeBSD/os_freebsd.c	2009-02-16 15:07:32.000000000 -0500
@@ -652,7 +652,11 @@
   oss_cdev_t *cdev;
 #ifndef VDEV_SUPPORT
   struct fileinfo _fi, * fi = &_fi;
+#if __FreeBSD_version >= 800062
+  dev = dev2unit (bsd_dev);
+#else
   dev = minor (bsd_dev);
+#endif
   init_fileinfo (fi, flags);
 #else
   struct fileinfo * fi;
@@ -686,7 +690,11 @@
   oss_cdev_t *cdev;
 #ifndef VDEV_SUPPORT
   struct fileinfo _fi, * fi = &_fi;
+#if __FreeBSD_version >= 800062
+  dev = dev2unit (bsd_dev);
+#else
   dev = minor (bsd_dev);
+#endif
   init_fileinfo (fi, flags);
 #else
   struct fileinfo * fi;
@@ -714,7 +722,11 @@
 static int
 oss_open (struct cdev *bsd_dev, int flags, int mode, struct thread *p)
 {
+#if __FreeBSD_version >= 800062
+  int dev = dev2unit (bsd_dev);
+#else
   int dev = minor (bsd_dev);
+#endif
   oss_cdev_t *cdev;
   struct fileinfo fi;
   int tmpdev, retval;
@@ -759,7 +771,11 @@
   oss_cdev_t *cdev;
 #ifndef VDEV_SUPPORT
   struct fileinfo _fi, * fi = &_fi;
+#if __FreeBSD_version >= 800062
+  dev = dev2unit (bsd_dev);
+#else
   dev = minor (bsd_dev);
+#endif
   init_fileinfo (fi, flags);
 #else
   struct fileinfo * fi;
@@ -792,7 +808,11 @@
   oss_cdev_t *cdev;
 #ifndef VDEV_SUPPORT
   struct fileinfo _fi, * fi = &_fi;
+#if __FreeBSD_version >= 800062
+  dev = dev2unit (bsd_dev);
+#else
   dev = minor (bsd_dev);
+#endif
   init_fileinfo (fi, mode);
 #else
   struct fileinfo * fi;
@@ -827,7 +847,11 @@
   int err;
 #ifndef VDEV_SUPPORT
   struct fileinfo _fi, * fi = &_fi;
+#if __FreeBSD_version >= 800062
+  dev = dev2unit (bsd_dev);
+#else
   dev = minor (bsd_dev);
+#endif
   init_fileinfo (fi, 0);
 #else
   struct fileinfo * fi;
@@ -870,7 +894,11 @@
   dmap_p dmap = NULL;
   int err;
 #ifndef VDEV_SUPPORT
+#if __FreeBSD_version >= 800062
+  dev = dev2unit (bsd_dev);
+#else
   dev = minor (bsd_dev);
+#endif
 #else
   struct fileinfo * fi;
   if (oss_file_get_private ((void **)&fi)) return ENXIO;
