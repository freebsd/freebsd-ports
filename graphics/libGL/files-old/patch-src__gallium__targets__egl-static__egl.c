--- ./src/gallium/targets/egl-static/egl.c.orig	2014-02-03 18:42:39.000000000 +0100
+++ ./src/gallium/targets/egl-static/egl.c	2014-02-15 21:11:55.000000000 +0100
@@ -29,9 +29,12 @@
 #include "egldriver.h"
 #include "egllog.h"
 
-#ifdef HAVE_LIBUDEV
+#if defined(HAVE_LIBUDEV)
 #include <stdio.h> /* for sscanf */
 #include <libudev.h>
+#elif defined(HAVE_LIBDEVQ)
+#include <libdevq.h>
+#include <stdlib.h>
 #endif
 
 #define DRIVER_MAP_GALLIUM_ONLY
@@ -108,6 +111,20 @@
    return (*chip_id >= 0);
 }
 
+#elif defined(HAVE_LIBDEVQ)
+
+static boolean
+drm_fd_get_pci_id(int fd, int *vendor_id, int *chip_id)
+{
+   int ret;
+
+   ret = devq_device_get_pciid_from_fd(fd, vendor_id, chip_id);
+   if (ret < 0)
+      return FALSE;
+
+   return TRUE;
+}
+
 #elif defined(PIPE_OS_ANDROID) && !defined(_EGL_NO_DRM)
 
 #include <xf86drm.h>
