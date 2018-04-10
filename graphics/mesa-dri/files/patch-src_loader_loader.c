commit db8519a369261cdedda50852facc45616d4eba28
Author: Greg V <greg@unrelenting.technology>
Date:   Mon Oct 23 23:20:40 2017 +0300

    loader: use drmGetDeviceNameFromFd2 from libdrm
    
    Reduce code duplication and automatically benefit from OS-specific
    fixes to libdrm (e.g. in FreeBSD ports).
    
    API was introduced with 2.4.74 and we already require 2.4.75 globally.
    
    Bugzilla: https://bugs.freedesktop.org/show_bug.cgi?id=103283
    Reviewed-by: Eric Engestrom <eric.engestrom@imgtec.com>
    Reviewed-by: Emil Velikov <emil.velikov@collabora.com>

--- src/loader/loader.c.orig	2017-12-21 17:31:21 UTC
+++ src/loader/loader.c
@@ -245,30 +245,7 @@ int loader_get_user_preferred_fd(int default_fd, bool 
 #endif
 
 #if defined(HAVE_LIBDRM)
-static int
-dev_node_from_fd(int fd, unsigned int *maj, unsigned int *min)
-{
-   struct stat buf;
 
-   if (fstat(fd, &buf) < 0) {
-      log_(_LOADER_WARNING, "MESA-LOADER: failed to stat fd %d\n", fd);
-      return -1;
-   }
-
-   if (!S_ISCHR(buf.st_mode)) {
-      log_(_LOADER_WARNING, "MESA-LOADER: fd %d not a character device\n", fd);
-      return -1;
-   }
-
-   *maj = major(buf.st_rdev);
-   *min = minor(buf.st_rdev);
-
-   return 0;
-}
-#endif
-
-#if defined(HAVE_LIBDRM)
-
 static int
 drm_get_pci_id_for_fd(int fd, int *vendor_id, int *chip_id)
 {
@@ -312,18 +289,7 @@ loader_get_pci_id_for_fd(int fd, int *vendor_id, int *
 static char *
 drm_get_device_name_for_fd(int fd)
 {
-   unsigned int maj, min;
-   char buf[0x40];
-   int n;
-
-   if (dev_node_from_fd(fd, &maj, &min) < 0)
-      return NULL;
-
-   n = snprintf(buf, sizeof(buf), DRM_DEV_NAME, DRM_DIR_NAME, min);
-   if (n == -1 || n >= sizeof(buf))
-      return NULL;
-
-   return strdup(buf);
+   return drmGetDeviceNameFromFd2(fd);
 }
 #endif
 
