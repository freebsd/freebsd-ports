--- ./src/gbm/main/common.h.orig	2014-02-03 18:42:39.000000000 +0100
+++ ./src/gbm/main/common.h	2014-02-15 21:11:55.000000000 +0100
@@ -28,10 +28,12 @@
 #ifndef _COMMON_H_
 #define _COMMON_H_
 
+#if defined(HAVE_LIBUDEV)
 #include <libudev.h>
 
 struct udev_device *
 _gbm_udev_device_new_from_fd(struct udev *udev, int fd);
+#endif
 
 char *
 _gbm_fd_get_device_name(int fd);
