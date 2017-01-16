--- xf86drm.c.orig	2017-01-15 13:16:10 UTC
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
@@ -532,6 +540,7 @@ static int drmGetMinorType(int minor)
     }
 }
 
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
 static const char *drmGetMinorName(int type)
 {
     switch (type) {
@@ -545,6 +554,7 @@ static const char *drmGetMinorName(int t
         return NULL;
     }
 }
+#endif
 
 /**
  * Open the device by bus ID.
@@ -2817,6 +2827,15 @@ static char *drmGetMinorNameForFD(int fd
 
 out_close_dir:
     closedir(sysdir);
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+    struct stat buf;
+    char name[64];
+
+    fstat(fd, &buf);
+    snprintf(name, sizeof(name), "/dev/%s",
+             devname(buf.st_rdev, S_IFCHR));
+
+    return strdup(name);
 #else
 #warning "Missing implementation of drmGetMinorNameForFD"
 #endif
@@ -2854,12 +2873,19 @@ static int drmParseSubsystemType(int maj
         return DRM_BUS_PCI;
 
     return -EINVAL;
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+    /* XXX: Don't know how to get the subsystem type, hardcode for now.
+     * The code following the call to this function needs depends on
+     * information provided by the /pci subsystem on linux. No replacement
+     * found yet for FreeBSD. */
+    return DRM_BUS_PCI;
 #else
 #warning "Missing implementation of drmParseSubsystemType"
     return -EINVAL;
 #endif
 }
 
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
 static int drmParsePciBusInfo(int maj, int min, drmPciBusInfoPtr info)
 {
 #ifdef __linux__
@@ -2901,6 +2927,61 @@ static int drmParsePciBusInfo(int maj, i
     return -EINVAL;
 #endif
 }
+#else
+
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
+        snprintf(hacked_path, length, DRM_DIR_NAME "/card%i", number);
+    } else if (strcmp(path, DRM_DIR_NAME "/renderD") > 0) {
+        start = 16;
+        number = strtonum(&path[start], 0, 256, &errstr) - 128;
+        snprintf(hacked_path, length, DRM_DIR_NAME "/card%i", number);
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
 
 static int drmCompareBusInfo(drmDevicePtr a, drmDevicePtr b)
 {
@@ -2971,6 +3052,31 @@ static int drmParsePciDeviceInfo(const c
     device->subdevice_id = config[46] | (config[47] << 8);
 
     return 0;
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+    int fd, vendor_id = 0, device_id = 0, subvendor_id = 0, 
+        subdevice_id = 0, revision_id = 0;
+    char path[PATH_MAX + 1];
+    char hacked_path[PATH_MAX + 1];
+
+    snprintf(path, PATH_MAX, DRM_DIR_NAME "/%s", d_name);
+    drmBSDDeviceNameHack(path, hacked_path, PATH_MAX);
+
+    fd = open(hacked_path, O_RDONLY);
+
+    if (fd < 0)
+        return -errno;
+
+    devq_device_get_pciid_full_from_fd(fd, &vendor_id, &device_id,
+	&subvendor_id, &subdevice_id, &revision_id);
+
+    device->vendor_id = (uint16_t) vendor_id;
+    device->device_id = (uint16_t) device_id;
+    device->subvendor_id = (uint16_t) subvendor_id;
+    device->subdevice_id = (uint16_t) subdevice_id;
+    device->revision_id = (uint8_t) revision_id;
+
+    close(fd);
+    return 0;
 #else
 #warning "Missing implementation of drmParsePciDeviceInfo"
     return -EINVAL;
@@ -3030,7 +3136,12 @@ static int drmProcessPciDevice(drmDevice
 
     (*device)->businfo.pci = (drmPciBusInfoPtr)addr;
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+    ret = drmParsePciBusInfoBSD(node, (*device)->businfo.pci);
+#else
     ret = drmParsePciBusInfo(maj, min, (*device)->businfo.pci);
+#endif
+
     if (ret)
         goto free_device;
 
