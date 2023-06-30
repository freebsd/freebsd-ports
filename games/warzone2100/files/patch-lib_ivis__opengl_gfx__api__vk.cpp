lib/ivis_opengl/gfx_api_vk.cpp:524:3: error: no member named 'throwResultException' in namespace 'vk'; did you mean 'vk::detail::throwResultException'?
                vk::throwResultException( result, "vmaCreateBuffer" );
                ^~~~~~~~~~~~~~~~~~~~~~~~
                vk::detail::throwResultException
/usr/local/include/vulkan/vulkan.hpp:6639:41: note: 'vk::detail::throwResultException' declared here
    [[noreturn]] VULKAN_HPP_INLINE void throwResultException( Result result, char const * message )
                                        ^
lib/ivis_opengl/gfx_api_vk.cpp:1543:4: error: no member named 'throwResultException' in namespace 'vk'; did you mean 'vk::detail::throwResultException'?
                        vk::throwResultException(result.result, "createGraphicsPipeline");
                        ^~~~~~~~~~~~~~~~~~~~~~~~
                        vk::detail::throwResultException
/usr/local/include/vulkan/vulkan.hpp:6639:41: note: 'vk::detail::throwResultException' declared here
    [[noreturn]] VULKAN_HPP_INLINE void throwResultException( Result result, char const * message )
                                        ^
lib/ivis_opengl/gfx_api_vk.cpp:1607:3: error: no member named 'throwResultException' in namespace 'vk'; did you mean 'vk::detail::throwResultException'?
                vk::throwResultException( result, "vmaCreateBuffer" );
                ^~~~~~~~~~~~~~~~~~~~~~~~
                vk::detail::throwResultException
/usr/local/include/vulkan/vulkan.hpp:6639:41: note: 'vk::detail::throwResultException' declared here
    [[noreturn]] VULKAN_HPP_INLINE void throwResultException( Result result, char const * message )
                                        ^
lib/ivis_opengl/gfx_api_vk.cpp:1740:3: error: no member named 'throwResultException' in namespace 'vk'; did you mean 'vk::detail::throwResultException'?
                vk::throwResultException( result, "vmaCreateImage" );
                ^~~~~~~~~~~~~~~~~~~~~~~~
                vk::detail::throwResultException
/usr/local/include/vulkan/vulkan.hpp:6639:41: note: 'vk::detail::throwResultException' declared here
    [[noreturn]] VULKAN_HPP_INLINE void throwResultException( Result result, char const * message )
                                        ^

--- lib/ivis_opengl/gfx_api_vk.cpp.orig	2023-04-16 17:42:55 UTC
+++ lib/ivis_opengl/gfx_api_vk.cpp
@@ -521,7 +521,7 @@ void BlockBufferAllocator::allocateNewBlock(uint32_t m
 	if (result != vk::Result::eSuccess)
 	{
 		// Failed to allocate memory!
-		vk::throwResultException( result, "vmaCreateBuffer" );
+		vk::detail::throwResultException( result, "vmaCreateBuffer" );
 	}
 
 	if (autoMap)
@@ -1540,7 +1540,7 @@ VkPSO::VkPSO(vk::Device _dev,
 			object = std::move(result.value);
 			break;
 		default:
-			vk::throwResultException(result.result, "createGraphicsPipeline");
+			vk::detail::throwResultException(result.result, "createGraphicsPipeline");
 	}
 }
 
@@ -1604,7 +1604,7 @@ void VkBuf::allocateBufferObject(const std::size_t& si
 	if (result != vk::Result::eSuccess)
 	{
 		// Failed to allocate memory!
-		vk::throwResultException( result, "vmaCreateBuffer" );
+		vk::detail::throwResultException( result, "vmaCreateBuffer" );
 	}
 
 	buffer_size = size;
@@ -1737,7 +1737,7 @@ VkTexture::VkTexture(const VkRoot& root, const std::si
 	if (result != vk::Result::eSuccess)
 	{
 		// Failed to allocate memory!
-		vk::throwResultException( result, "vmaCreateImage" );
+		vk::detail::throwResultException( result, "vmaCreateImage" );
 	}
 
 	if (root.debugUtilsExtEnabled)
