--- core/rend/vulkan/vmallocator.h.orig	2024-11-10 23:58:42 UTC
+++ core/rend/vulkan/vmallocator.h
@@ -64,7 +64,7 @@ class Allocation (public)
 			return allocInfo.pMappedData;
 		void *p;
 		VkResult res = vmaMapMemory(allocator, allocation, &p);
-		vk::resultCheck(static_cast<vk::Result>(res), "vmaMapMemory failed");
+		vk::detail::resultCheck(static_cast<vk::Result>(res), "vmaMapMemory failed");
 		VkMemoryPropertyFlags flags;
 		vmaGetMemoryTypeProperties(allocator, allocInfo.memoryType, &flags);
 		if ((flags & VK_MEMORY_PROPERTY_HOST_CACHED_BIT) && (flags & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT) == 0)
@@ -114,7 +114,7 @@ class VMAllocator (public)
 		VmaAllocation vmaAllocation;
 		VmaAllocationInfo allocInfo;
 		VkResult rc = vmaAllocateMemory(allocator, (VkMemoryRequirements*)&memoryRequirements, &allocCreateInfo, &vmaAllocation, &allocInfo);
-		vk::resultCheck(static_cast<vk::Result>(rc), "vmaAllocateMemory failed");
+		vk::detail::resultCheck(static_cast<vk::Result>(rc), "vmaAllocateMemory failed");
 		return Allocation(allocator, vmaAllocation, allocInfo);
 	}
 
@@ -123,7 +123,7 @@ class VMAllocator (public)
 		VmaAllocation vmaAllocation;
 		VmaAllocationInfo allocInfo;
 		VkResult rc = vmaAllocateMemoryForImage(allocator, (VkImage)image, &allocCreateInfo, &vmaAllocation, &allocInfo);
-		vk::resultCheck(static_cast<vk::Result>(rc), "vmaAllocateMemoryForImage failed");
+		vk::detail::resultCheck(static_cast<vk::Result>(rc), "vmaAllocateMemoryForImage failed");
 		vmaBindImageMemory(allocator, vmaAllocation, (VkImage)image);
 
 		return Allocation(allocator, vmaAllocation, allocInfo);
@@ -134,7 +134,7 @@ class VMAllocator (public)
 		VmaAllocation vmaAllocation;
 		VmaAllocationInfo allocInfo;
 		VkResult rc = vmaAllocateMemoryForBuffer(allocator, (VkBuffer)buffer, &allocCreateInfo, &vmaAllocation, &allocInfo);
-		vk::resultCheck(static_cast<vk::Result>(rc), "vmaAllocateMemoryForBuffer failed");
+		vk::detail::resultCheck(static_cast<vk::Result>(rc), "vmaAllocateMemoryForBuffer failed");
 		vmaBindBufferMemory(allocator, vmaAllocation, (VkBuffer)buffer);
 
 		return Allocation(allocator, vmaAllocation, allocInfo);
