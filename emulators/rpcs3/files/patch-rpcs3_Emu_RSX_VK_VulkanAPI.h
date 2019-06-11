Revert https://github.com/RPCS3/rpcs3/commit/39fa1d7031e3 to unbreak
with devel/vulkan-headers < 1.1.96

In file included from rpcs3/Emu/RSX/VK/VKFormats.cpp:2:
In file included from rpcs3/Emu/RSX/VK/VKFormats.h:2:
rpcs3/Emu/RSX/VK/VKHelpers.h:603:5: error: unknown type name 'VkPhysicalDeviceFloat16Int8FeaturesKHR'; did you mean 'VkPhysicalDeviceMultiviewFeaturesKHR'?
                                VkPhysicalDeviceFloat16Int8FeaturesKHR shader_support_info{};
                                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- rpcs3/Emu/RSX/VK/VulkanAPI.h.orig	2019-06-10 11:57:03 UTC
+++ rpcs3/Emu/RSX/VK/VulkanAPI.h
@@ -14,6 +14,19 @@
 #include "define_new_memleakdetect.h"
 #include "Utilities/types.h"
 
+#if VK_HEADER_VERSION < 95
+
+typedef struct VkPhysicalDeviceFloat16Int8FeaturesKHR {
+    VkStructureType    sType;
+    void*              pNext;
+    VkBool32           shaderFloat16;
+    VkBool32           shaderInt8;
+} VkPhysicalDeviceFloat16Int8FeaturesKHR;
+
+#define VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT16_INT8_FEATURES_KHR VkStructureType(1000082000)
+
+#endif
+
 namespace vk
 {
 	void init();
