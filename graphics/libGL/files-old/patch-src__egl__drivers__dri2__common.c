--- src/egl/drivers/dri2/common.c.orig	2012-11-24 18:57:41.000000000 +0100
+++ src/egl/drivers/dri2/common.c	2014-03-02 11:36:35.000000000 +0100
@@ -35,11 +35,11 @@
 
 #include "egl_dri2.h"
 
-#ifdef HAVE_LIBUDEV
-
 #define DRIVER_MAP_DRI2_ONLY
 #include "pci_ids/pci_id_driver_map.h"
 
+#ifdef HAVE_LIBUDEV
+
 #include <libudev.h>
 
 static struct udev_device *
@@ -141,4 +141,70 @@
    return driver;
 }
 
+#elif defined(HAVE_LIBDEVQ)
+
+#include <libdevq.h>
+#include <stdlib.h>
+
+char *
+dri2_get_device_name_for_fd(int fd)
+{
+   int ret;
+   char *device_name = NULL;
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
+
+   return device_name;
+}
+
+char *
+dri2_get_driver_for_fd(int fd)
+{
+   int ret;
+   char *driver = NULL;
+   int vendor_id, chip_id, i, j;
+
+   ret = devq_device_get_pciid_from_fd(fd, &vendor_id, &chip_id);
+   if (ret < 0) {
+      _eglLog(_EGL_WARNING, "EGL-DRI2: malformed or no PCI ID");
+      goto out;
+   }
+
+   for (i = 0; driver_map[i].driver; i++) {
+      if (vendor_id != driver_map[i].vendor_id)
+         continue;
+      if (driver_map[i].num_chips_ids == -1) {
+         driver = strdup(driver_map[i].driver);
+         _eglLog(_EGL_DEBUG, "pci id for %d: %04x:%04x, driver %s",
+                 fd, vendor_id, chip_id, driver);
+         goto out;
+      }
+
+      for (j = 0; j < driver_map[i].num_chips_ids; j++)
+         if (driver_map[i].chip_ids[j] == chip_id) {
+            driver = strdup(driver_map[i].driver);
+            _eglLog(_EGL_DEBUG, "pci id for %d: %04x:%04x, driver %s",
+                    fd, vendor_id, chip_id, driver);
+            goto out;
+         }
+   }
+
+out:
+   return driver;
+}
+
 #endif /* HAVE_LIBUDEV */
