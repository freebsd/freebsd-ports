--- gpu/command_buffer/tests/gl_test_utils.h.orig	2020-05-26 07:48:26 UTC
+++ gpu/command_buffer/tests/gl_test_utils.h
@@ -120,7 +120,7 @@ class GpuCommandBufferTestEGL {
     return gfx::HasExtension(gl_extensions_, extension);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Create GLImageNativePixmap filled in with the given pixels.
   scoped_refptr<gl::GLImageNativePixmap> CreateGLImageNativePixmap(
       gfx::BufferFormat format,
