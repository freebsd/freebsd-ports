--- gpu/command_buffer/tests/gl_test_utils.cc.orig	2022-05-25 04:01:02 UTC
+++ gpu/command_buffer/tests/gl_test_utils.cc
@@ -24,7 +24,7 @@
 #include "ui/gl/gl_version_info.h"
 #include "ui/gl/init/gl_factory.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/gl/gl_image_native_pixmap.h"
 #endif
 
@@ -454,7 +454,7 @@ void GpuCommandBufferTestEGL::RestoreGLDefault() {
   window_system_binding_info_ = gl::GLWindowSystemBindingInfo();
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 scoped_refptr<gl::GLImageNativePixmap>
 GpuCommandBufferTestEGL::CreateGLImageNativePixmap(gfx::BufferFormat format,
                                                    gfx::Size size,
