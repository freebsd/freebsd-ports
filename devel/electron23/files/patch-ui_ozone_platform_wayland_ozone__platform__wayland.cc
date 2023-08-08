--- ui/ozone/platform/wayland/ozone_platform_wayland.cc.orig	2023-02-01 18:43:52 UTC
+++ ui/ozone/platform/wayland/ozone_platform_wayland.cc
@@ -68,7 +68,7 @@
 #include "ui/ozone/platform/wayland/host/wayland_cursor_factory.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/platform/wayland/host/linux_ui_delegate_wayland.h"
 #endif
 
@@ -243,7 +243,7 @@ class OzonePlatformWayland : public OzonePlatform,
 
     supported_buffer_formats_ =
         connection_->buffer_manager_host()->GetSupportedBufferFormats();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     linux_ui_delegate_ =
         std::make_unique<LinuxUiDelegateWayland>(connection_.get());
 #endif
@@ -446,7 +446,7 @@ class OzonePlatformWayland : public OzonePlatform,
   DrmRenderNodePathFinder path_finder_;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<LinuxUiDelegateWayland> linux_ui_delegate_;
 #endif
 };
