--- core/rend/vulkan/vmallocator.cpp.orig	2024-11-10 23:58:20 UTC
+++ core/rend/vulkan/vmallocator.cpp
@@ -71,5 +71,5 @@ void VMAllocator::Init(vk::PhysicalDevice physicalDevi
 #endif
 
 	VkResult rc = vmaCreateAllocator(&allocatorInfo, &allocator);
-	vk::resultCheck(static_cast<vk::Result>(rc), "vmaCreateAllocator failed");
+	vk::detail::resultCheck(static_cast<vk::Result>(rc), "vmaCreateAllocator failed");
 }
