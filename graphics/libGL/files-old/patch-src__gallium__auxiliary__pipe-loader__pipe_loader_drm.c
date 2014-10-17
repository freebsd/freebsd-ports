--- ./src/gallium/auxiliary/pipe-loader/pipe_loader_drm.c.orig	2014-02-03 18:42:39.000000000 +0100
+++ ./src/gallium/auxiliary/pipe-loader/pipe_loader_drm.c	2014-02-15 21:11:55.000000000 +0100
@@ -32,7 +32,14 @@
 
 #include <fcntl.h>
 #include <stdio.h>
+
+#if defined(HAVE_LIBUDEV)
 #include <libudev.h>
+#elif defined(HAVE_LIBDEVQ)
+#include <libdevq.h>
+#include <stdlib.h>
+#endif
+
 #include <xf86drm.h>
 
 #ifdef HAVE_PIPE_LOADER_XCB
@@ -62,6 +69,7 @@
 static boolean
 find_drm_pci_id(struct pipe_loader_drm_device *ddev)
 {
+#if defined(HAVE_LIBUDEV)
    struct udev *udev = NULL;
    struct udev_device *parent, *device = NULL;
    struct stat stat;
@@ -100,6 +108,17 @@
       udev_unref(udev);
 
    return FALSE;
+#elif defined(HAVE_LIBDEVQ)
+   int ret;
+
+   ret = devq_device_get_pciid_from_fd(ddev->fd,
+       &ddev->base.u.pci.vendor_id,
+       &ddev->base.u.pci.chip_id);
+   if (ret < 0)
+      return FALSE;
+
+   return TRUE;
+#endif
 }
 
 static boolean
