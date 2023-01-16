https://gitlab.freedesktop.org/mesa/mesa/-/issues/8193

--- src/compiler/nir/nir_convert_ycbcr.c.orig	2023-01-29 04:42:32 UTC
+++ src/compiler/nir/nir_convert_ycbcr.c
@@ -21,6 +21,17 @@
  * IN THE SOFTWARE.
  */
 
+/* Disable all WSI flags defined project-wide in meson.build */
+#undef VK_USE_PLATFORM_ANDROID_KHR
+#undef VK_USE_PLATFORM_DISPLAY_KHR
+#undef VK_USE_PLATFORM_MACOS_MVK
+#undef VK_USE_PLATFORM_METAL_EXT
+#undef VK_USE_PLATFORM_WAYLAND_KHR
+#undef VK_USE_PLATFORM_WIN32_KHR
+#undef VK_USE_PLATFORM_XCB_KHR
+#undef VK_USE_PLATFORM_XLIB_KHR
+#undef VK_USE_PLATFORM_XLIB_XRANDR_EXT
+
 #include "nir_vulkan.h"
 #include "vulkan/util/vk_format.h"
 #include "vulkan/runtime/vk_ycbcr_conversion.h"
