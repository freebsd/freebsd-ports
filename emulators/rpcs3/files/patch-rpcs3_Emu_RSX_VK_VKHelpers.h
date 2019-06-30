In file included from rpcs3/Emu/RSX/VK/VKFormats.cpp:2:
In file included from rpcs3/Emu/RSX/VK/VKFormats.h:2:
rpcs3/Emu/RSX/VK/VKHelpers.h:465:3: error: unknown type name 'VkPhysicalDeviceDriverPropertiesKHR'; did you mean 'VkPhysicalDeviceGroupPropertiesKHR'?
                VkPhysicalDeviceDriverPropertiesKHR driver_properties{};
                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                VkPhysicalDeviceGroupPropertiesKHR

--- rpcs3/Emu/RSX/VK/VKHelpers.h.orig	2019-06-29 15:48:42 UTC
+++ rpcs3/Emu/RSX/VK/VKHelpers.h
@@ -47,6 +47,48 @@
 #define FRAME_PRESENT_TIMEOUT 1000000ull // 1 second
 #define GENERAL_WAIT_TIMEOUT  100000ull  // 100ms
 
+#if VK_HEADER_VERSION < 92
+#define VK_MAX_DRIVER_NAME_SIZE_KHR       256
+#define VK_MAX_DRIVER_INFO_SIZE_KHR       256
+
+#define VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR (VkStructureType)1000196000
+
+typedef enum VkDriverIdKHR {
+    VK_DRIVER_ID_AMD_PROPRIETARY_KHR = 1,
+    VK_DRIVER_ID_AMD_OPEN_SOURCE_KHR = 2,
+    VK_DRIVER_ID_MESA_RADV_KHR = 3,
+    VK_DRIVER_ID_NVIDIA_PROPRIETARY_KHR = 4,
+    VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS_KHR = 5,
+    VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA_KHR = 6,
+    VK_DRIVER_ID_IMAGINATION_PROPRIETARY_KHR = 7,
+    VK_DRIVER_ID_QUALCOMM_PROPRIETARY_KHR = 8,
+    VK_DRIVER_ID_ARM_PROPRIETARY_KHR = 9,
+    VK_DRIVER_ID_GOOGLE_SWIFTSHADER_KHR = 10,
+    VK_DRIVER_ID_GGP_PROPRIETARY_KHR = 11,
+    VK_DRIVER_ID_BROADCOM_PROPRIETARY_KHR = 12,
+    VK_DRIVER_ID_BEGIN_RANGE_KHR = VK_DRIVER_ID_AMD_PROPRIETARY_KHR,
+    VK_DRIVER_ID_END_RANGE_KHR = VK_DRIVER_ID_BROADCOM_PROPRIETARY_KHR,
+    VK_DRIVER_ID_RANGE_SIZE_KHR = (VK_DRIVER_ID_BROADCOM_PROPRIETARY_KHR - VK_DRIVER_ID_AMD_PROPRIETARY_KHR + 1),
+    VK_DRIVER_ID_MAX_ENUM_KHR = 0x7FFFFFFF
+} VkDriverIdKHR;
+
+typedef struct VkConformanceVersionKHR {
+    uint8_t    major;
+    uint8_t    minor;
+    uint8_t    subminor;
+    uint8_t    patch;
+} VkConformanceVersionKHR;
+
+typedef struct VkPhysicalDeviceDriverPropertiesKHR {
+    VkStructureType            sType;
+    void*                      pNext;
+    VkDriverIdKHR              driverID;
+    char                       driverName[VK_MAX_DRIVER_NAME_SIZE_KHR];
+    char                       driverInfo[VK_MAX_DRIVER_INFO_SIZE_KHR];
+    VkConformanceVersionKHR    conformanceVersion;
+} VkPhysicalDeviceDriverPropertiesKHR;
+#endif
+
 namespace rsx
 {
 	class fragment_texture;
