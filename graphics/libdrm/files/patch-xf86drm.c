--- xf86drm.c.orig	2017-01-30 19:04:05 UTC
+++ xf86drm.c
@@ -62,6 +62,10 @@
 #endif
 #include <math.h>
 
+#ifdef HAVE_LIBDEVQ
+#include "libdevq.h"
+#endif
+
 /* Not all systems have MAP_FAILED defined */
 #ifndef MAP_FAILED
 #define MAP_FAILED ((void *)-1)
@@ -82,8 +86,12 @@
 #define DRM_RENDER_MINOR_NAME   "renderD"
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
-#define DRM_MAJOR 145
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#define DRM_MAJOR 0
+#endif
+
+#if defined(__DragonFly__)
+#define DRM_MAJOR 65 /* was 145 XXX needs checking */
 #endif
 
 #ifdef __NetBSD__
@@ -548,6 +556,7 @@ static int drmGetMinorType(int minor)
     }
 }
 
+#if !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__DragonFly__)
 static const char *drmGetMinorName(int type)
 {
     switch (type) {
@@ -561,6 +570,7 @@ static const char *drmGetMinorName(int t
         return NULL;
     }
 }
+#endif
 
 /**
  * Open the device by bus ID.
@@ -2734,7 +2744,7 @@ int drmGetNodeTypeFromFd(int fd)
     maj = major(sbuf.st_rdev);
     min = minor(sbuf.st_rdev);
 
-    if (maj != DRM_MAJOR || !S_ISCHR(sbuf.st_mode)) {
+    if (DRM_MAJOR && maj != DRM_MAJOR || !S_ISCHR(sbuf.st_mode)) {
         errno = EINVAL;
         return -1;
     }
@@ -2833,6 +2843,15 @@ static char *drmGetMinorNameForFD(int fd
 
 out_close_dir:
     closedir(sysdir);
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    struct stat buf;
+    char name[64];
+
+    fstat(fd, &buf);
+    snprintf(name, sizeof(name), "/dev/%s",
+             devname(buf.st_rdev, S_IFCHR));
+
+    return strdup(name);
 #else
     struct stat sbuf;
     char buf[PATH_MAX + 1];
@@ -2960,7 +2979,7 @@ static int drmParseSubsystemType(int maj
         return DRM_BUS_HOST1X;
 
     return -EINVAL;
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
     return DRM_BUS_PCI;
 #else
 #warning "Missing implementation of drmParseSubsystemType"
@@ -3023,6 +3042,61 @@ static int drmParsePciBusInfo(int maj, i
 #endif
 }
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+/*
+ * XXX temporary workaround, because FreeBSD doesn't provide 
+ * pcibus device sysctl trees for renderD and controlD nodes (yet)
+ */
+static void
+drmBSDDeviceNameHack(const char *path, char *hacked_path, int length)
+{
+    int start, number;
+    const char *errstr;
+
+    if (strcmp(path, DRM_DIR_NAME "/controlD") > 0) {
+        start = 17;
+        number = strtonum(&path[start], 0, 256, &errstr) - 64;
+        snprintf(hacked_path, length, "%s/card%i", DRM_DIR_NAME, number);
+    } else if (strcmp(path, DRM_DIR_NAME "/renderD") > 0) {
+        start = 16;
+        number = strtonum(&path[start], 0, 256, &errstr) - 128;
+        snprintf(hacked_path, length, "%s/card%i", DRM_DIR_NAME, number);
+    } else
+        snprintf(hacked_path, length, "%s", path);
+
+  return;
+}
+
+static int
+drmParsePciBusInfoBSD(const char *path, drmPciBusInfoPtr info)
+{
+    int fd, ret;
+    int domain = 0, bus = 0, slot = 0, function = 0;
+    char hacked_path[PATH_MAX + 1];
+
+    drmBSDDeviceNameHack(path, hacked_path, PATH_MAX);
+    fd = open(hacked_path, O_RDONLY);
+
+    if (fd < 0)
+        return -errno;
+
+    ret = devq_device_get_pcibusaddr(fd, &domain, &bus, &slot, &function);
+
+    if (ret < 0) {
+        close(fd);
+        return -1;
+    }
+
+    info->domain = (uint16_t) domain;
+    info->bus = (uint8_t) bus;
+    info->dev = (uint8_t) slot;
+    info->func = (uint8_t) function;
+
+    close(fd);
+    return 0;
+}
+#endif
+
 static int drmCompareBusInfo(drmDevicePtr a, drmDevicePtr b)
 {
     if (a == NULL || b == NULL)
@@ -3188,6 +3262,36 @@ static int drmParsePciDeviceInfo(int maj
 #endif
 }
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+static int drmParsePciDeviceInfoBSD(const char *path,
+                                    drmPciDeviceInfoPtr device,
+                                    uint32_t flags)
+{
+    int fd, vendor_id = 0, device_id = 0, subvendor_id = 0,
+        subdevice_id = 0, revision_id = 0;
+    char hacked_path[PATH_MAX + 1];
+
+    drmBSDDeviceNameHack(path, hacked_path, PATH_MAX);
+
+    fd = open(hacked_path, O_RDONLY);
+ 
+    if (fd < 0)
+        return -errno;
+ 
+    devq_device_get_pciid_full_from_fd(fd, &vendor_id, &device_id,
+        &subvendor_id, &subdevice_id, &revision_id);
+
+    device->vendor_id = (uint16_t) vendor_id;
+    device->device_id = (uint16_t) device_id;
+    device->subvendor_id = (uint16_t) subvendor_id;
+    device->subdevice_id = (uint16_t) subdevice_id;
+    device->revision_id = (uint8_t) revision_id;
+ 
+    close(fd);
+    return 0;
+}
+#endif
+
 static void drmFreePlatformDevice(drmDevicePtr device)
 {
     if (device->deviceinfo.platform) {
@@ -3308,7 +3412,11 @@ static int drmProcessPciDevice(drmDevice
 
     dev->businfo.pci = (drmPciBusInfoPtr)addr;
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    ret = drmParsePciBusInfoBSD(node, dev->businfo.pci);
+#else
     ret = drmParsePciBusInfo(maj, min, dev->businfo.pci);
+#endif
     if (ret)
         goto free_device;
 
@@ -3316,8 +3424,11 @@ static int drmProcessPciDevice(drmDevice
     if (fetch_deviceinfo) {
         addr += sizeof(drmPciBusInfo);
         dev->deviceinfo.pci = (drmPciDeviceInfoPtr)addr;
-
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+        ret = drmParsePciDeviceInfoBSD(node, dev->deviceinfo.pci, flags);
+#else
         ret = drmParsePciDeviceInfo(maj, min, dev->deviceinfo.pci, flags);
+#endif
         if (ret)
             goto free_device;
     }
@@ -3786,7 +3897,7 @@ int drmGetDevice2(int fd, uint32_t flags
     maj = major(sbuf.st_rdev);
     min = minor(sbuf.st_rdev);
 
-    if (maj != DRM_MAJOR || !S_ISCHR(sbuf.st_mode))
+    if (DRM_MAJOR && maj != DRM_MAJOR || !S_ISCHR(sbuf.st_mode))
         return -EINVAL;
 
     subsystem_type = drmParseSubsystemType(maj, min);
@@ -3814,7 +3925,7 @@ int drmGetDevice2(int fd, uint32_t flags
         maj = major(sbuf.st_rdev);
         min = minor(sbuf.st_rdev);
 
-        if (maj != DRM_MAJOR || !S_ISCHR(sbuf.st_mode))
+        if (DRM_MAJOR && maj != DRM_MAJOR || !S_ISCHR(sbuf.st_mode))
             continue;
 
         if (drmParseSubsystemType(maj, min) != subsystem_type)
@@ -3964,7 +4075,7 @@ int drmGetDevices2(uint32_t flags, drmDe
         maj = major(sbuf.st_rdev);
         min = minor(sbuf.st_rdev);
 
-        if (maj != DRM_MAJOR || !S_ISCHR(sbuf.st_mode))
+        if (DRM_MAJOR && maj != DRM_MAJOR || !S_ISCHR(sbuf.st_mode))
             continue;
 
         subsystem_type = drmParseSubsystemType(maj, min);
@@ -4108,7 +4219,7 @@ char *drmGetDeviceNameFromFd2(int fd)
     maj = major(sbuf.st_rdev);
     min = minor(sbuf.st_rdev);
 
-    if (maj != DRM_MAJOR || !S_ISCHR(sbuf.st_mode))
+    if (DRM_MAJOR && maj != DRM_MAJOR || !S_ISCHR(sbuf.st_mode))
         return NULL;
 
     node_type = drmGetMinorType(min);
