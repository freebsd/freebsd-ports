--- src/loader/loader.c.orig	2015-08-22 12:01:00.000000000 +0200
+++ src/loader/loader.c	2015-08-24 10:50:05.251081000 +0200
@@ -70,7 +70,7 @@
 #include <stdarg.h>
 #include <stdio.h>
 #include <string.h>
-#ifdef HAVE_LIBUDEV
+#if defined(HAVE_LIBUDEV) || defined(HAVE_LIBDEVQ)
 #include <assert.h>
 #include <dlfcn.h>
 #include <unistd.h>
@@ -505,6 +505,54 @@ sysfs_get_pci_id_for_fd(int fd, int *ven
 }
 #endif
 
+#if defined(HAVE_LIBDEVQ)
+#include <libdevq.h>
+
+static void *devq_handle = NULL;
+
+static void *
+devq_dlopen_handle(void)
+{
+   if (!devq_handle) {
+      devq_handle = dlopen("libdevq.so.0", RTLD_LOCAL | RTLD_LAZY);
+   }
+
+   return devq_handle;
+}
+
+static void *
+asserted_dlsym(void *dlopen_handle, const char *name)
+{
+   void *result = dlsym(dlopen_handle, name);
+   assert(result);
+   return result;
+}
+
+#define DEVQ_SYMBOL(ret, name, args) \
+   ret (*name) args = asserted_dlsym(devq_dlopen_handle(), #name);
+
+static int
+devq_get_pci_id_from_fd(int fd, int *vendor_id, int *chip_id)
+{
+   int ret;
+   DEVQ_SYMBOL(int, devq_device_get_pciid_from_fd,
+               (int fd, int *vendor_id, int *chip_id));
+
+   *chip_id = -1;
+
+   ret = devq_device_get_pciid_from_fd(fd, vendor_id, chip_id);
+   if (ret < 0) {
+      log_(_LOADER_WARNING, "MESA-LOADER: could not get PCI ID\n");
+      goto out;
+   }
+
+out:
+   return (*chip_id >= 0);
+}
+
+#endif
+
+
 #if defined(HAVE_LIBDRM)
 /* for i915 */
 #include <i915_drm.h>
@@ -588,6 +636,10 @@ loader_get_pci_id_for_fd(int fd, int *ve
    if (sysfs_get_pci_id_for_fd(fd, vendor_id, chip_id))
       return 1;
 #endif
+#if HAVE_LIBDEVQ
+   if (devq_get_pci_id_from_fd(fd, vendor_id, chip_id))
+      return 1;
+#endif
 #if HAVE_LIBDRM
    if (drm_get_pci_id_for_fd(fd, vendor_id, chip_id))
       return 1;
@@ -685,6 +737,13 @@ loader_get_device_name_for_fd(int fd)
    if ((result = sysfs_get_device_name_for_fd(fd)))
       return result;
 #endif
+#if HAVE_LIBDEVQ
+#if 0
+/* XXX implement this function in libdevq */
+   if ((result = devq_device_get_name_for_fd(fd)))
+      return result;
+#endif
+#endif
    return result;
 }
 
