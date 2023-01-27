--- gpu/command_buffer/tests/gl_test_utils.h.orig	2022-07-22 17:30:31 UTC
+++ gpu/command_buffer/tests/gl_test_utils.h
@@ -122,7 +122,7 @@ class GpuCommandBufferTestEGL {
     return gfx::HasExtension(gl_extensions_, extension);
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Create GLImageNativePixmap filled in with the given pixels.
   scoped_refptr<gl::GLImageNativePixmap> CreateGLImageNativePixmap(
       gfx::BufferFormat format,
