--- ./src/gbm/main/common.c.orig	2014-02-03 18:42:39.000000000 +0100
+++ ./src/gbm/main/common.c	2014-02-15 21:11:55.000000000 +0100
@@ -28,7 +28,13 @@
 #include <stdio.h>
 #include <string.h>
 
+#if defined(HAVE_LIBUDEV)
 #include <libudev.h>
+#elif defined(HAVE_LIBDEVQ)
+#include <libdevq.h>
+#include <stdlib.h>
+#endif
+
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
@@ -36,6 +42,7 @@
 #include "common.h"
 #include "gbmint.h"
 
+#if defined(HAVE_LIBUDEV)
 GBM_EXPORT struct udev_device *
 _gbm_udev_device_new_from_fd(struct udev *udev, int fd)
 {
@@ -56,14 +63,17 @@
 
    return device;
 }
+#endif /* defined(HAVE_LIBUDEV) */
 
 GBM_EXPORT char *
 _gbm_fd_get_device_name(int fd)
 {
+   char *device_name = NULL;
+
+#if defined(HAVE_LIBUDEV)
    struct udev *udev;
    struct udev_device *device;
    const char *const_device_name;
-   char *device_name = NULL;
 
    udev = udev_new();
    device = _gbm_udev_device_new_from_fd(udev, fd);
@@ -78,6 +88,25 @@
 out:
    udev_device_unref(device);
    udev_unref(udev);
+#elif defined(HAVE_LIBDEVQ)
+   int ret;
+   size_t device_name_len;
+
+   ret = devq_device_get_devpath_from_fd(fd,
+       NULL, &device_name_len);
+   if (ret < 0)
+      return (NULL);
+
+   device_name = malloc(device_name_len + 1);
+   ret = devq_device_get_devpath_from_fd(fd,
+       device_name, &device_name_len);
+   if (ret < 0) {
+      free(device_name);
+      return (NULL);
+   }
+
+   device_name[device_name_len] = '\0';
+#endif
 
    return device_name;
 }
