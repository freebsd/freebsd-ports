--- app/streaming/video/ffmpeg-renderers/plvk.h.orig	2024-07-23 05:26:28 UTC
+++ app/streaming/video/ffmpeg-renderers/plvk.h
@@ -54,7 +54,11 @@ class PlVkRenderer : public IFFmpegRenderer { (private
     // The libplacebo rendering state
     pl_log m_Log = nullptr;
     pl_vk_inst m_PlVkInstance = nullptr;
+#if VK_USE_64_BIT_PTR_DEFINES == 1
     VkSurfaceKHR m_VkSurface = nullptr;
+#else
+    VkSurfaceKHR m_VkSurface = 0;
+#endif
     pl_vulkan m_Vulkan = nullptr;
     pl_swapchain m_Swapchain = nullptr;
     pl_renderer m_Renderer = nullptr;
