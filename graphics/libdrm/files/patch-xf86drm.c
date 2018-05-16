--- xf86drm.c.orig	2018-05-13 08:59:08 UTC
+++ xf86drm.c
@@ -46,6 +46,9 @@
 #include <signal.h>
 #include <time.h>
 #include <sys/types.h>
+#ifdef HAVE_SYS_SYSCTL_H
+#include <sys/sysctl.h>
+#endif
 #include <sys/stat.h>
 #define stat_t struct stat
 #include <sys/ioctl.h>
@@ -59,6 +62,10 @@
 #endif
 #include <math.h>
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#include <sys/pciio.h>
+#endif
+
 /* Not all systems have MAP_FAILED defined */
 #ifndef MAP_FAILED
 #define MAP_FAILED ((void *)-1)
@@ -69,18 +76,8 @@
 
 #include "util_math.h"
 
-#ifdef __OpenBSD__
-#define DRM_PRIMARY_MINOR_NAME  "drm"
-#define DRM_CONTROL_MINOR_NAME  "drmC"
-#define DRM_RENDER_MINOR_NAME   "drmR"
-#else
-#define DRM_PRIMARY_MINOR_NAME  "card"
-#define DRM_CONTROL_MINOR_NAME  "controlD"
-#define DRM_RENDER_MINOR_NAME   "renderD"
-#endif
-
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
-#define DRM_MAJOR 145
+#define DRM_MAJOR 0	/* Major ID unused on systems with devfs */
 #endif
 
 #ifdef __NetBSD__
@@ -177,7 +174,7 @@ void drmFree(void *pt)
 }
 
 /**
- * Call ioctl, restarting if it is interupted
+ * Call ioctl, restarting if it is interrupted
  */
 int
 drmIoctl(int fd, unsigned long request, void *arg)
@@ -220,6 +217,89 @@ drmHashEntry *drmGetEntry(int fd)
     return entry;
 }
 
+static int drmGetMinorBase(int type)
+{
+    switch (type) {
+        case DRM_NODE_PRIMARY:
+        case DRM_NODE_CONTROL:
+        case DRM_NODE_RENDER:
+            return type << 6;
+        default:
+            return -1;
+    };
+}
+
+static int drmGetMinorType(int minor)
+{
+    if (minor < 0)
+        return -1;
+
+    int type = minor >> 6;
+    switch (type) {
+        case DRM_NODE_PRIMARY:
+        case DRM_NODE_CONTROL:
+        case DRM_NODE_RENDER:
+            return type;
+        default:
+            return -1;
+    }
+}
+
+#ifdef __linux__
+static const char *drmGetMinorName(int type)
+{
+    switch (type) {
+        case DRM_NODE_PRIMARY:
+            return DRM_PRIMARY_MINOR_NAME;
+        case DRM_NODE_CONTROL:
+            return DRM_CONTROL_MINOR_NAME;
+        case DRM_NODE_RENDER:
+            return DRM_RENDER_MINOR_NAME;
+        default:
+            return NULL;
+    }
+}
+#endif
+
+static const char *drmGetDeviceName(int type)
+{
+    switch (type) {
+        case DRM_NODE_PRIMARY:
+            return DRM_DEV_NAME;
+        case DRM_NODE_CONTROL:
+            return DRM_CONTROL_DEV_NAME;
+        case DRM_NODE_RENDER:
+            return DRM_RENDER_DEV_NAME;
+        default:
+            return NULL;
+    }
+}
+
+static int drmGetNodeNumber(const char *name)
+{
+    size_t name_len = strnlen(name, DRM_NODE_NAME_MAX);
+    while (name_len && isdigit(name[name_len - 1]))
+        --name_len;
+    return strtol(name + name_len, NULL, 10);
+}
+
+static int drmGetNodeType(const char *name)
+{
+    if (strncmp(name, DRM_PRIMARY_MINOR_NAME,
+                sizeof(DRM_PRIMARY_MINOR_NAME) - 1) == 0)
+        return DRM_NODE_PRIMARY;
+
+    if (strncmp(name, DRM_CONTROL_MINOR_NAME,
+                sizeof(DRM_CONTROL_MINOR_NAME ) - 1) == 0)
+        return DRM_NODE_CONTROL;
+
+    if (strncmp(name, DRM_RENDER_MINOR_NAME,
+                sizeof(DRM_RENDER_MINOR_NAME) - 1) == 0)
+        return DRM_NODE_RENDER;
+
+    return -1;
+}
+
 /**
  * Compare two busid strings
  *
@@ -287,7 +367,7 @@ static int drmMatchBusID(const char *id1, const char *
  *
  * \internal
  * Checks for failure. If failure was caused by signal call chown again.
- * If any other failure happened then it will output error mesage using
+ * If any other failure happened then it will output error message using
  * drmMsg() call.
  */
 #if !UDEV
@@ -324,8 +404,8 @@ static int chown_check_return(const char *path, uid_t 
 static int drmOpenDevice(dev_t dev, int minor, int type)
 {
     stat_t          st;
-    const char      *dev_name;
-    char            buf[64];
+    const char      *dev_name = drmGetDeviceName(type);
+    char            buf[DRM_NODE_NAME_MAX];
     int             fd;
     mode_t          devmode = DRM_DEV_MODE, serv_mode;
     gid_t           serv_group;
@@ -335,21 +415,14 @@ static int drmOpenDevice(dev_t dev, int minor, int typ
     gid_t           group   = DRM_DEV_GID;
 #endif
 
-    switch (type) {
-    case DRM_NODE_PRIMARY:
-        dev_name = DRM_DEV_NAME;
-        break;
-    case DRM_NODE_CONTROL:
-        dev_name = DRM_CONTROL_DEV_NAME;
-        break;
-    case DRM_NODE_RENDER:
-        dev_name = DRM_RENDER_DEV_NAME;
-        break;
-    default:
+    if (!dev_name)
         return -EINVAL;
-    };
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    sprintf(buf, dev_name, DRM_DIR_NAME, minor + drmGetMinorBase(type));
+#else
     sprintf(buf, dev_name, DRM_DIR_NAME, minor);
+#endif
     drmMsg("drmOpenDevice: node name is %s\n", buf);
 
     if (drm_server_info && drm_server_info->get_perms) {
@@ -453,27 +526,20 @@ wait_for_udev:
 static int drmOpenMinor(int minor, int create, int type)
 {
     int  fd;
-    char buf[64];
-    const char *dev_name;
+    char buf[DRM_NODE_NAME_MAX];
+    const char *dev_name = drmGetDeviceName(type);
 
     if (create)
         return drmOpenDevice(makedev(DRM_MAJOR, minor), minor, type);
 
-    switch (type) {
-    case DRM_NODE_PRIMARY:
-        dev_name = DRM_DEV_NAME;
-        break;
-    case DRM_NODE_CONTROL:
-        dev_name = DRM_CONTROL_DEV_NAME;
-        break;
-    case DRM_NODE_RENDER:
-        dev_name = DRM_RENDER_DEV_NAME;
-        break;
-    default:
+    if (!dev_name)
         return -EINVAL;
-    };
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    sprintf(buf, dev_name, DRM_DIR_NAME, minor + drmGetMinorBase(type));
+#else
     sprintf(buf, dev_name, DRM_DIR_NAME, minor);
+#endif
     if ((fd = open(buf, O_RDWR, 0)) >= 0)
         return fd;
     return -errno;
@@ -514,51 +580,6 @@ int drmAvailable(void)
     return retval;
 }
 
-static int drmGetMinorBase(int type)
-{
-    switch (type) {
-    case DRM_NODE_PRIMARY:
-        return 0;
-    case DRM_NODE_CONTROL:
-        return 64;
-    case DRM_NODE_RENDER:
-        return 128;
-    default:
-        return -1;
-    };
-}
-
-static int drmGetMinorType(int minor)
-{
-    int type = minor >> 6;
-
-    if (minor < 0)
-        return -1;
-
-    switch (type) {
-    case DRM_NODE_PRIMARY:
-    case DRM_NODE_CONTROL:
-    case DRM_NODE_RENDER:
-        return type;
-    default:
-        return -1;
-    }
-}
-
-static const char *drmGetMinorName(int type)
-{
-    switch (type) {
-    case DRM_NODE_PRIMARY:
-        return DRM_PRIMARY_MINOR_NAME;
-    case DRM_NODE_CONTROL:
-        return DRM_CONTROL_MINOR_NAME;
-    case DRM_NODE_RENDER:
-        return DRM_RENDER_MINOR_NAME;
-    default:
-        return NULL;
-    }
-}
-
 /**
  * Open the device by bus ID.
  *
@@ -2737,33 +2758,40 @@ int drmDropMaster(int fd)
 
 char *drmGetDeviceNameFromFd(int fd)
 {
-    char name[128];
-    struct stat sbuf;
-    dev_t d;
-    int i;
-
     /* The whole drmOpen thing is a fiasco and we need to find a way
      * back to just using open(2).  For now, however, lets just make
      * things worse with even more ad hoc directory walking code to
      * discover the device file name. */
 
+    stat_t sbuf;
     fstat(fd, &sbuf);
-    d = sbuf.st_rdev;
+    dev_t d = sbuf.st_rdev;
 
-    for (i = 0; i < DRM_MAX_MINOR; i++) {
+    for (int i = 0; i < DRM_MAX_MINOR; i++) {
+        char name[DRM_NODE_NAME_MAX];
         snprintf(name, sizeof name, DRM_DEV_NAME, DRM_DIR_NAME, i);
         if (stat(name, &sbuf) == 0 && sbuf.st_rdev == d)
-            break;
+            return strdup(name);
     }
-    if (i == DRM_MAX_MINOR)
-        return NULL;
-
-    return strdup(name);
+    return NULL;
 }
 
 int drmGetNodeTypeFromFd(int fd)
 {
-    struct stat sbuf;
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    char *name = drmGetDeviceNameFromFd2(fd);
+    if (!name) {
+        errno = ENODEV;
+        return -1;
+    }
+
+    int type = drmGetNodeType(name);
+    free(name);
+    if (type < 0)
+        errno = ENODEV;
+    return type;
+#else
+    stat_t sbuf;
     int maj, min, type;
 
     if (fstat(fd, &sbuf))
@@ -2781,6 +2809,7 @@ int drmGetNodeTypeFromFd(int fd)
     if (type == -1)
         errno = ENODEV;
     return type;
+#endif
 }
 
 int drmPrimeHandleToFD(int fd, uint32_t handle, uint32_t flags, int *prime_fd)
@@ -2820,7 +2849,7 @@ static char *drmGetMinorNameForFD(int fd, int type)
 #ifdef __linux__
     DIR *sysdir;
     struct dirent *ent;
-    struct stat sbuf;
+    stat_t sbuf;
     const char *name = drmGetMinorName(type);
     int len;
     char dev_name[64], buf[64];
@@ -2856,13 +2885,35 @@ static char *drmGetMinorNameForFD(int fd, int type)
         }
     }
     return NULL;
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    const char *dev_name = drmGetDeviceName(type);
+    if (!dev_name)
+        return NULL;
+
+    char *name = drmGetDeviceNameFromFd2(fd);
+    if (!name)
+        return NULL;
+
+    int oldnum = drmGetNodeNumber(name);
+    int oldtype = drmGetMinorType(oldnum);
+    if (oldtype < 0) {
+        free(name);
+        return NULL;
+    }
+
+    int newnum = oldnum - drmGetMinorBase(oldtype) + drmGetMinorBase(type);
+    snprintf(name, DRM_NODE_NAME_MAX, dev_name, DRM_DIR_NAME, newnum);
+    return name;
 #else
-    struct stat sbuf;
-    char buf[PATH_MAX + 1];
-    const char *dev_name;
+    stat_t sbuf;
+    char buf[DRM_NODE_NAME_MAX];
+    const char *dev_name = drmGetDeviceName(type);
     unsigned int maj, min;
     int n, base;
 
+    if (!dev_name)
+        return NULL;
+
     if (fstat(fd, &sbuf))
         return NULL;
 
@@ -2872,20 +2923,6 @@ static char *drmGetMinorNameForFD(int fd, int type)
     if (maj != DRM_MAJOR || !S_ISCHR(sbuf.st_mode))
         return NULL;
 
-    switch (type) {
-    case DRM_NODE_PRIMARY:
-        dev_name = DRM_DEV_NAME;
-        break;
-    case DRM_NODE_CONTROL:
-        dev_name = DRM_CONTROL_DEV_NAME;
-        break;
-    case DRM_NODE_RENDER:
-        dev_name = DRM_RENDER_DEV_NAME;
-        break;
-    default:
-        return NULL;
-    };
-
     base = drmGetMinorBase(type);
     if (base < 0)
         return NULL;
@@ -2982,7 +3019,7 @@ static int drmParseSubsystemType(int maj, int min)
         return DRM_BUS_HOST1X;
 
     return -EINVAL;
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
     return DRM_BUS_PCI;
 #else
 #warning "Missing implementation of drmParseSubsystemType"
@@ -2990,7 +3027,8 @@ static int drmParseSubsystemType(int maj, int min)
 #endif
 }
 
-static int drmParsePciBusInfo(int maj, int min, drmPciBusInfoPtr info)
+static int drmParsePciBusInfo(const char *node, int node_type,
+                              int maj, int min, drmPciBusInfoPtr info)
 {
 #ifdef __linux__
     unsigned int domain, bus, dev, func;
@@ -3039,6 +3077,60 @@ static int drmParsePciBusInfo(int maj, int min, drmPci
     info->func = pinfo.func;
 
     return 0;
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    /*
+     * Only the primary nodes can be mapped to hw.dri.%i via major/minor
+     * Determine the primary node by offset and use its major/minor pair
+     */
+    if (node_type != DRM_NODE_PRIMARY) {
+        char name[DRM_NODE_NAME_MAX];
+        snprintf(name, sizeof(name), DRM_DEV_NAME, DRM_DIR_NAME,
+                 drmGetNodeNumber(node) - drmGetMinorBase(node_type));
+
+        stat_t sbuf;
+        if (stat(name, &sbuf))
+            return -errno;
+
+        maj = major(sbuf.st_rdev);
+        min = minor(sbuf.st_rdev);
+    }
+    /*
+     * Major/minor appear after the driver name in the hw.dri.%i.name node
+     * Find the node with matching major/minor pair and parse the bus ID,
+     * which may be after the name or may be alone in hw.dri.%i.busid
+     */
+    #define bus_fmt "pci:%04x:%02x:%02x.%u"
+    #define name_fmt "%*s %x " bus_fmt
+    for (int i = 0; i < DRM_MAX_MINOR; ++i) {
+        char name[16], value[256];
+        size_t length = sizeof(value);
+        snprintf(name, sizeof(name), "hw.dri.%i.name", i);
+        if (sysctlbyname(name, value, &length, NULL, 0))
+            continue;
+
+        value[length] = '\0';
+        unsigned int rdev = 0, domain = 0, bus = 0, slot = 0, func = 0;
+        int vals = sscanf(value, name_fmt, &rdev, &domain, &bus, &slot, &func);
+
+	if (vals >= 1 && rdev == makedev(maj,min)) {
+            if (vals < 5) {
+                /* busid not in the name, try busid */
+                length = sizeof(value);
+                snprintf(name, sizeof(name), "hw.dri.%i.busid", i);
+                if (sysctlbyname(name, value, &length, NULL, 0))
+                    break;
+                value[length] = '\0';
+                if (sscanf(value, bus_fmt, &domain, &bus, &slot, &func) != 4)
+                    break;
+            }
+            info->domain = domain;
+            info->bus = bus;
+            info->dev = slot;
+            info->func = func;
+            return 0;
+        }
+    }
+    return -ENODEV;
 #else
 #warning "Missing implementation of drmParsePciBusInfo"
     return -EINVAL;
@@ -3073,32 +3165,6 @@ int drmDevicesEqual(drmDevicePtr a, drmDevicePtr b)
     return 0;
 }
 
-static int drmGetNodeType(const char *name)
-{
-    if (strncmp(name, DRM_PRIMARY_MINOR_NAME,
-        sizeof(DRM_PRIMARY_MINOR_NAME) - 1) == 0)
-        return DRM_NODE_PRIMARY;
-
-    if (strncmp(name, DRM_CONTROL_MINOR_NAME,
-        sizeof(DRM_CONTROL_MINOR_NAME ) - 1) == 0)
-        return DRM_NODE_CONTROL;
-
-    if (strncmp(name, DRM_RENDER_MINOR_NAME,
-        sizeof(DRM_RENDER_MINOR_NAME) - 1) == 0)
-        return DRM_NODE_RENDER;
-
-    return -EINVAL;
-}
-
-static int drmGetMaxNodeName(void)
-{
-    return sizeof(DRM_DIR_NAME) +
-           MAX3(sizeof(DRM_PRIMARY_MINOR_NAME),
-                sizeof(DRM_CONTROL_MINOR_NAME),
-                sizeof(DRM_RENDER_MINOR_NAME)) +
-           3 /* length of the node number */;
-}
-
 #ifdef __linux__
 static int parse_separate_sysfs_files(int maj, int min,
                                       drmPciDeviceInfoPtr device,
@@ -3168,6 +3234,7 @@ static int parse_config_sysfs_file(int maj, int min,
 #endif
 
 static int drmParsePciDeviceInfo(int maj, int min,
+                                 drmPciBusInfoPtr info,
                                  drmPciDeviceInfoPtr device,
                                  uint32_t flags)
 {
@@ -3204,6 +3271,43 @@ static int drmParsePciDeviceInfo(int maj, int min,
     device->subdevice_id = pinfo.subdevice_id;
 
     return 0;
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    struct pci_conf_io pc;
+    struct pci_match_conf patterns[1];
+    struct pci_conf results[1];
+
+    int fd = open("/dev/pci", O_RDONLY, 0);
+    if (fd < 0)
+        return -errno;
+
+    bzero(&patterns, sizeof(patterns));
+    patterns[0].pc_sel.pc_domain = info->domain;
+    patterns[0].pc_sel.pc_bus = info->bus;
+    patterns[0].pc_sel.pc_dev = info->dev;
+    patterns[0].pc_sel.pc_func = info->func;
+    patterns[0].flags = PCI_GETCONF_MATCH_DOMAIN | PCI_GETCONF_MATCH_BUS
+                      | PCI_GETCONF_MATCH_DEV | PCI_GETCONF_MATCH_FUNC;
+    bzero(&pc, sizeof(struct pci_conf_io));
+    pc.num_patterns = 1;
+    pc.pat_buf_len = sizeof(patterns);
+    pc.patterns = patterns;
+    pc.match_buf_len = sizeof(results);
+    pc.matches = results;
+
+    if (ioctl(fd, PCIOCGETCONF, &pc) || pc.status == PCI_GETCONF_ERROR) {
+        int error = errno;
+        close(fd);
+        return -error;
+    }
+    close(fd);
+
+    device->vendor_id = results[0].pc_vendor;
+    device->device_id = results[0].pc_device;
+    device->subvendor_id = results[0].pc_subvendor;
+    device->subdevice_id = results[0].pc_subdevice;
+    device->revision_id = results[0].pc_revid;
+
+    return 0;
 #else
 #warning "Missing implementation of drmParsePciDeviceInfo"
     return -EINVAL;
@@ -3284,7 +3388,7 @@ static drmDevicePtr drmDeviceAlloc(unsigned int type, 
     unsigned int i;
     char *ptr;
 
-    max_node_length = ALIGN(drmGetMaxNodeName(), sizeof(void *));
+    max_node_length = ALIGN(DRM_NODE_NAME_MAX, sizeof(void *));
     extra = DRM_NODE_MAX * (sizeof(void *) + max_node_length);
 
     size = sizeof(*device) + extra + bus_size + device_size;
@@ -3330,7 +3434,7 @@ static int drmProcessPciDevice(drmDevicePtr *device,
 
     dev->businfo.pci = (drmPciBusInfoPtr)addr;
 
-    ret = drmParsePciBusInfo(maj, min, dev->businfo.pci);
+    ret = drmParsePciBusInfo(node, node_type, maj, min, dev->businfo.pci);
     if (ret)
         goto free_device;
 
@@ -3339,7 +3443,7 @@ static int drmProcessPciDevice(drmDevicePtr *device,
         addr += sizeof(drmPciBusInfo);
         dev->deviceinfo.pci = (drmPciDeviceInfoPtr)addr;
 
-        ret = drmParsePciDeviceInfo(maj, min, dev->deviceinfo.pci, flags);
+        ret = drmParsePciDeviceInfo(maj, min, dev->businfo.pci, dev->deviceinfo.pci, flags);
         if (ret)
             goto free_device;
     }
@@ -3689,7 +3793,7 @@ static void drmFoldDuplicatedDevices(drmDevicePtr loca
                 local_devices[i]->available_nodes |= local_devices[j]->available_nodes;
                 node_type = log2(local_devices[j]->available_nodes);
                 memcpy(local_devices[i]->nodes[node_type],
-                       local_devices[j]->nodes[node_type], drmGetMaxNodeName());
+                       local_devices[j]->nodes[node_type], DRM_NODE_NAME_MAX);
                 drmFreeDevice(&local_devices[j]);
             }
         }
@@ -3707,7 +3811,7 @@ drm_device_validate_flags(uint32_t flags)
  * Get information about the opened drm device
  *
  * \param fd file descriptor of the drm device
- * \param flags feature/behaviour bitmask
+ * \param flags feature/behavior bitmask
  * \param device the address of a drmDevicePtr where the information
  *               will be allocated in stored
  *
@@ -3725,8 +3829,8 @@ int drmGetDevice2(int fd, uint32_t flags, drmDevicePtr
      * Avoid stat'ing all of /dev needlessly by implementing this custom path.
      */
     drmDevicePtr     d;
-    struct stat      sbuf;
-    char             node[PATH_MAX + 1];
+    stat_t           sbuf;
+    char             node[DRM_NODE_NAME_MAX];
     const char      *dev_name;
     int              node_type, subsystem_type;
     int              maj, min, n, ret, base;
@@ -3747,26 +3851,16 @@ int drmGetDevice2(int fd, uint32_t flags, drmDevicePtr
     if (node_type == -1)
         return -ENODEV;
 
-    switch (node_type) {
-    case DRM_NODE_PRIMARY:
-        dev_name = DRM_DEV_NAME;
-        break;
-    case DRM_NODE_CONTROL:
-        dev_name = DRM_CONTROL_DEV_NAME;
-        break;
-    case DRM_NODE_RENDER:
-        dev_name = DRM_RENDER_DEV_NAME;
-        break;
-    default:
+    dev_name = drmGetDeviceName(node_type);
+    if (!dev_name)
         return -EINVAL;
-    };
 
     base = drmGetMinorBase(node_type);
     if (base < 0)
         return -EINVAL;
 
-    n = snprintf(node, PATH_MAX, dev_name, DRM_DIR_NAME, min - base);
-    if (n == -1 || n >= PATH_MAX)
+    n = snprintf(node, sizeof(node), dev_name, DRM_DIR_NAME, min - base);
+    if (n == -1 || n >= sizeof(node))
       return -errno;
     if (stat(node, &sbuf))
         return -EINVAL;
@@ -3787,8 +3881,8 @@ int drmGetDevice2(int fd, uint32_t flags, drmDevicePtr
     drmDevicePtr d;
     DIR *sysdir;
     struct dirent *dent;
-    struct stat sbuf;
-    char node[PATH_MAX + 1];
+    stat_t sbuf;
+    char node[DRM_NODE_NAME_MAX];
     int node_type, subsystem_type;
     int maj, min;
     int ret, i, node_count;
@@ -3808,7 +3902,7 @@ int drmGetDevice2(int fd, uint32_t flags, drmDevicePtr
     maj = major(sbuf.st_rdev);
     min = minor(sbuf.st_rdev);
 
-    if (maj != DRM_MAJOR || !S_ISCHR(sbuf.st_mode))
+    if ((DRM_MAJOR && maj != DRM_MAJOR) || !S_ISCHR(sbuf.st_mode))
         return -EINVAL;
 
     subsystem_type = drmParseSubsystemType(maj, min);
@@ -3829,14 +3923,14 @@ int drmGetDevice2(int fd, uint32_t flags, drmDevicePtr
         if (node_type < 0)
             continue;
 
-        snprintf(node, PATH_MAX, "%s/%s", DRM_DIR_NAME, dent->d_name);
+        snprintf(node, sizeof(node), "%s/%s", DRM_DIR_NAME, dent->d_name);
         if (stat(node, &sbuf))
             continue;
 
         maj = major(sbuf.st_rdev);
         min = minor(sbuf.st_rdev);
 
-        if (maj != DRM_MAJOR || !S_ISCHR(sbuf.st_mode))
+        if ((DRM_MAJOR && maj != DRM_MAJOR) || !S_ISCHR(sbuf.st_mode))
             continue;
 
         if (drmParseSubsystemType(maj, min) != subsystem_type)
@@ -3934,7 +4028,7 @@ int drmGetDevice(int fd, drmDevicePtr *device)
 /**
  * Get drm devices on the system
  *
- * \param flags feature/behaviour bitmask
+ * \param flags feature/behavior bitmask
  * \param devices the array of devices with drmDevicePtr elements
  *                can be NULL to get the device number first
  * \param max_devices the maximum number of devices for the array
@@ -3953,8 +4047,8 @@ int drmGetDevices2(uint32_t flags, drmDevicePtr device
     drmDevicePtr device;
     DIR *sysdir;
     struct dirent *dent;
-    struct stat sbuf;
-    char node[PATH_MAX + 1];
+    stat_t sbuf;
+    char node[DRM_NODE_NAME_MAX];
     int node_type, subsystem_type;
     int maj, min;
     int ret, i, node_count, device_count;
@@ -3979,14 +4073,14 @@ int drmGetDevices2(uint32_t flags, drmDevicePtr device
         if (node_type < 0)
             continue;
 
-        snprintf(node, PATH_MAX, "%s/%s", DRM_DIR_NAME, dent->d_name);
+        snprintf(node, sizeof(node), "%s/%s", DRM_DIR_NAME, dent->d_name);
         if (stat(node, &sbuf))
             continue;
 
         maj = major(sbuf.st_rdev);
         min = minor(sbuf.st_rdev);
 
-        if (maj != DRM_MAJOR || !S_ISCHR(sbuf.st_mode))
+        if ((DRM_MAJOR && maj != DRM_MAJOR) || !S_ISCHR(sbuf.st_mode))
             continue;
 
         subsystem_type = drmParseSubsystemType(maj, min);
@@ -4094,7 +4188,7 @@ int drmGetDevices(drmDevicePtr devices[], int max_devi
 char *drmGetDeviceNameFromFd2(int fd)
 {
 #ifdef __linux__
-    struct stat sbuf;
+    stat_t sbuf;
     char path[PATH_MAX + 1], *value;
     unsigned int maj, min;
 
@@ -4117,9 +4211,26 @@ char *drmGetDeviceNameFromFd2(int fd)
     free(value);
 
     return strdup(path);
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    stat_t sbuf;
+    if (fstat(fd, &sbuf))
+        return NULL;
+
+    dev_t rdev = sbuf.st_rdev;
+    /* minor numbers don't depend on node name suffix, search for a match */
+    for (int i = 0; i < DRM_MAX_MINOR; ++i) {
+        char node[DRM_NODE_NAME_MAX];
+        for (int j = 0; j < DRM_NODE_MAX; ++j) {
+            snprintf(node, sizeof(node), drmGetDeviceName(j),
+                     DRM_DIR_NAME, drmGetMinorBase(j) + i);
+            if (stat(node, &sbuf) == 0 && sbuf.st_rdev == rdev)
+                return strdup(node);
+        }
+    }
+    return NULL;
 #else
-    struct stat      sbuf;
-    char             node[PATH_MAX + 1];
+    stat_t           sbuf;
+    char             node[DRM_NODE_NAME_MAX];
     const char      *dev_name;
     int              node_type;
     int              maj, min, n, base;
@@ -4137,26 +4248,16 @@ char *drmGetDeviceNameFromFd2(int fd)
     if (node_type == -1)
         return NULL;
 
-    switch (node_type) {
-    case DRM_NODE_PRIMARY:
-        dev_name = DRM_DEV_NAME;
-        break;
-    case DRM_NODE_CONTROL:
-        dev_name = DRM_CONTROL_DEV_NAME;
-        break;
-    case DRM_NODE_RENDER:
-        dev_name = DRM_RENDER_DEV_NAME;
-        break;
-    default:
+    dev_name = drmGetDeviceName(node_type);
+    if (!dev_name)
         return NULL;
-    };
 
     base = drmGetMinorBase(node_type);
     if (base < 0)
         return NULL;
 
-    n = snprintf(node, PATH_MAX, dev_name, DRM_DIR_NAME, min - base);
-    if (n == -1 || n >= PATH_MAX)
+    n = snprintf(node, sizeof(node), dev_name, DRM_DIR_NAME, min - base);
+    if (n == -1 || n >= sizeof(node))
       return NULL;
 
     return strdup(node);
