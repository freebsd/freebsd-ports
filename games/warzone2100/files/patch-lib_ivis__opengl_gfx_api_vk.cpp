--- lib/ivis_opengl/gfx_api_vk.cpp.orig	2026-04-07 13:57:52 UTC
+++ lib/ivis_opengl/gfx_api_vk.cpp
@@ -4255,10 +4255,10 @@ vk::SurfaceFormatKHR chooseSwapSurfaceFormat(const std
 vk::SurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<vk::SurfaceFormatKHR>& availableFormats)
 {
 	const auto desiredFormats = std::array<vk::SurfaceFormatKHR, 4> {
-		vk::SurfaceFormatKHR{ vk::Format::eA2B10G10R10UnormPack32, vk::ColorSpaceKHR::eVkColorspaceSrgbNonlinear },
-		vk::SurfaceFormatKHR{ vk::Format::eA2R10G10B10UnormPack32, vk::ColorSpaceKHR::eVkColorspaceSrgbNonlinear },
-		vk::SurfaceFormatKHR{ vk::Format::eB8G8R8A8Unorm, vk::ColorSpaceKHR::eVkColorspaceSrgbNonlinear },
-		vk::SurfaceFormatKHR{ vk::Format::eR8G8B8A8Unorm, vk::ColorSpaceKHR::eVkColorspaceSrgbNonlinear }
+		vk::SurfaceFormatKHR{ vk::Format::eA2B10G10R10UnormPack32, vk::ColorSpaceKHR::eSrgbNonlinear },
+		vk::SurfaceFormatKHR{ vk::Format::eA2R10G10B10UnormPack32, vk::ColorSpaceKHR::eSrgbNonlinear },
+		vk::SurfaceFormatKHR{ vk::Format::eB8G8R8A8Unorm, vk::ColorSpaceKHR::eSrgbNonlinear },
+		vk::SurfaceFormatKHR{ vk::Format::eR8G8B8A8Unorm, vk::ColorSpaceKHR::eSrgbNonlinear }
 	};
 
 	if(availableFormats.size() == 1
@@ -4266,7 +4266,7 @@ vk::SurfaceFormatKHR chooseSwapSurfaceFormat(const std
 	{
 		// don't appear to be any preferred formats, so create one
 		vk::SurfaceFormatKHR format;
-		format.colorSpace = vk::ColorSpaceKHR::eVkColorspaceSrgbNonlinear;
+		format.colorSpace = vk::ColorSpaceKHR::eSrgbNonlinear;
 		format.format = vk::Format::eB8G8R8A8Unorm;
 		return format;
 	}
