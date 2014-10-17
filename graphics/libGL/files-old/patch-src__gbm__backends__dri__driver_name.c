--- ./src/gbm/backends/dri/driver_name.c.orig	2014-02-03 18:42:39.000000000 +0100
+++ ./src/gbm/backends/dri/driver_name.c	2014-02-15 21:11:55.000000000 +0100
@@ -29,7 +29,12 @@
 #include <stdio.h>
 #include <string.h>
 
+#if defined(HAVE_LIBUDEV)
 #include <libudev.h>
+#elif defined(HAVE_LIBDEVQ)
+#include <libdevq.h>
+#include <stdlib.h>
+#endif
 
 #include "gbm_driint.h"
 #define DRIVER_MAP_DRI2_ONLY
@@ -38,10 +43,12 @@
 char *
 dri_fd_get_driver_name(int fd)
 {
+   char *driver = NULL;
+
+#if defined(HAVE_LIBUDEV)
    struct udev *udev;
    struct udev_device *device, *parent;
    const char *pci_id;
-   char *driver = NULL;
    int vendor_id, chip_id, i, j;
 
    udev = udev_new();
@@ -84,6 +91,23 @@
 out:
    udev_device_unref(device);
    udev_unref(udev);
+#elif defined(HAVE_LIBDEVQ)
+   int ret;
+   size_t driver_len;
+
+   ret = devq_device_drm_get_drvname_from_fd(fd, NULL, &driver_len);
+   if (ret < 0)
+      return (NULL);
+
+   driver = malloc(driver_len + 1);
+   ret = devq_device_drm_get_drvname_from_fd(fd, driver, &driver_len);
+   if (ret < 0) {
+      free(driver);
+      return (NULL);
+   }
+
+   driver[driver_len] = '\0';
+#endif
 
    return driver;
 }
