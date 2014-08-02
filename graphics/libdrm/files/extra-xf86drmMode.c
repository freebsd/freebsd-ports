--- xf86drmMode.c.orig	2010-09-08 14:23:39.000000000 +0200
+++ xf86drmMode.c	2011-07-18 18:59:11.000000000 +0200
@@ -54,7 +54,7 @@
 
 static inline DRM_IOCTL(int fd, int cmd, void *arg)
 {
-	int ret = drmIoctl(fd, cmd, arg);
+	int ret = drmIoctl(fd, (unsigned)cmd, arg);
 	return ret < 0 ? -errno : ret;
 }
 
@@ -659,7 +659,7 @@
 */
 int drmCheckModesettingSupported(const char *busid)
 {
-#ifdef __linux__
+#if defined (__linux__)
 	char pci_dev_dir[1024];
 	int domain, bus, dev, func;
 	DIR *sysdir;
@@ -709,6 +709,8 @@
 	closedir(sysdir);
 	if (found)
 		return 0;
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+	return 0;
 #endif
 	return -ENOSYS;
 
