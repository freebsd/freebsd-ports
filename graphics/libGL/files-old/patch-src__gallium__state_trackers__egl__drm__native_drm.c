--- ./src/gallium/state_trackers/egl/drm/native_drm.c.orig	2014-02-03 18:42:39.000000000 +0100
+++ ./src/gallium/state_trackers/egl/drm/native_drm.c	2014-02-15 21:11:55.000000000 +0100
@@ -35,8 +35,11 @@
 
 #include "gbm_gallium_drmint.h"
 
-#ifdef HAVE_LIBUDEV
+#if defined(HAVE_LIBUDEV)
 #include <libudev.h>
+#elif defined(HAVE_LIBDEVQ)
+#include <libdevq.h>
+#include <stdlib.h>
 #endif
 
 static boolean
@@ -183,8 +186,26 @@
    udev_device_unref(device);
 outudev:
    udev_unref(udev);
+#elif defined(HAVE_LIBDEVQ)
+   int ret;
+   size_t device_name_len;
 
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
 #endif
+
    return device_name;
 }
 
