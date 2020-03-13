--- third_party/angle/src/gpu_info_util/SystemInfo_libpci.cpp.orig	2019-12-12 12:42:33 UTC
+++ third_party/angle/src/gpu_info_util/SystemInfo_libpci.cpp
@@ -12,6 +12,11 @@
 #include <pci/pci.h>
 #include <unistd.h>
 
+#if defined(__FreeBSD__)
+#include <fcntl.h>
+#include <sys/pciio.h>
+#endif
+
 #include "common/angleutils.h"
 #include "common/debug.h"
 
@@ -82,6 +87,75 @@ struct LibPCI : private angle::NonCopyable
 };
 
 }  // anonymous namespace
+
+#if defined(__FreeBSD__)
+// Adds an entry per PCI GPU found and fills the device and vendor ID.
+bool GetPCIDevicesFreeBSD(std::vector<GPUDeviceInfo> *devices)
+{
+    int fd;
+    struct pci_conf_io conf;
+    struct pci_conf *matches;
+    uint32_t offset = 0;
+
+    fd = open("/dev/pci", O_RDONLY);
+    if (fd < 0)
+        return false;
+
+    matches = new struct pci_conf[32];
+    conf.generation = 0;
+    do {
+        conf.pat_buf_len = 0;
+        conf.num_patterns = 0;
+        conf.patterns = NULL;
+        conf.match_buf_len = 32 * sizeof(struct pci_conf);
+        conf.num_matches = 32;
+        conf.matches = matches;
+        conf.offset = offset;
+        conf.status = PCI_GETCONF_ERROR;
+        if (ioctl(fd, PCIOCGETCONF, &conf) < 0) {
+            if (errno == ENODEV)
+                break;
+        }
+        /* PCI_GETCONF_LIST_CHANGED would require us to start over. */
+        if (conf.status == PCI_GETCONF_ERROR || conf.status == PCI_GETCONF_LIST_CHANGED) {
+            break;
+        }
+
+        for (unsigned int i = 0; i < conf.num_matches; i++) {
+            uint16_t device_class = (matches[i].pc_class << 8) |  matches[i].pc_subclass;
+
+            // Skip non-GPU devices
+            switch (device_class)
+            {
+                case PCI_CLASS_DISPLAY_VGA:
+                case PCI_CLASS_DISPLAY_XGA:
+                case PCI_CLASS_DISPLAY_3D:
+                    break;
+                default:
+                    continue;
+            }
+
+            // Skip unknown devices
+            if (matches[i].pc_vendor == 0 || matches[i].pc_device == 0) {
+                continue;
+            }
+
+            GPUDeviceInfo info;
+            info.vendorId = matches[i].pc_vendor;
+            info.deviceId = matches[i].pc_device;
+
+            devices->push_back(info);
+        }
+        offset += conf.num_matches;
+    } while (conf.status == PCI_GETCONF_MORE_DEVS);
+
+    delete[] matches;
+
+    close(fd);
+
+    return true;
+}
+#endif
 
 // Adds an entry per PCI GPU found and fills the device and vendor ID.
 bool GetPCIDevicesWithLibPCI(std::vector<GPUDeviceInfo> *devices)
