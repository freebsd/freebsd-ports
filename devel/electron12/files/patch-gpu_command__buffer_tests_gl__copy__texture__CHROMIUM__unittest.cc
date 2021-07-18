--- gpu/command_buffer/tests/gl_copy_texture_CHROMIUM_unittest.cc.orig	2021-04-14 01:08:50 UTC
+++ gpu/command_buffer/tests/gl_copy_texture_CHROMIUM_unittest.cc
@@ -258,7 +258,7 @@ void getExpectedColorAndMask(GLenum src_internal_forma
 
       setColor(adjusted_color[0], adjusted_color[1], adjusted_color[2],
                alpha_value, expected_color);
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       // The alpha channel values for LUMINANCE_ALPHA source don't work OK
       // on Mac or Linux, so skip comparison of those, see crbug.com/926579
       setColor(1, 1, 1, src_internal_format != GL_LUMINANCE_ALPHA,
@@ -637,8 +637,8 @@ class GLCopyTextureCHROMIUMES3Test : public GLCopyText
 
   bool ShouldSkipNorm16() const {
     DCHECK(!ShouldSkipTest());
-#if (defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
-     defined(OS_CHROMEOS)) &&                                   \
+#if (defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
+     defined(OS_CHROMEOS)) &&                                                      \
     (defined(ARCH_CPU_X86) || defined(ARCH_CPU_X86_64))
     // Make sure it's tested; it is safe to assume that the flag is always true
     // on desktop.
@@ -650,7 +650,7 @@ class GLCopyTextureCHROMIUMES3Test : public GLCopyText
 
   bool ShouldSkipRGBA16ToRGB10A2() const {
     DCHECK(!ShouldSkipTest());
-#if (defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS)) && \
+#if (defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && \
     (defined(ARCH_CPU_X86) || defined(ARCH_CPU_X86_64))
     // // TODO(crbug.com/1046873): Fails on mac and linux intel.
     return true;
