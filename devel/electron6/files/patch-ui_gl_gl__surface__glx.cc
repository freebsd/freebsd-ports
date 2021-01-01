--- ui/gl/gl_surface_glx.cc.orig	2019-09-10 11:14:39 UTC
+++ ui/gl/gl_surface_glx.cc
@@ -431,7 +431,10 @@ bool GLSurfaceGLX::InitializeOneOff() {
     return false;
   }
 
-  const auto& visual_info = gl::GLVisualPickerGLX::GetInstance()->rgba_visual();
+  const auto& visual_info = 
+    ui::IsCompositingManagerPresent()
+      ? gl::GLVisualPickerGLX::GetInstance()->rgba_visual()
+      : gl::GLVisualPickerGLX::GetInstance()->system_visual();
   g_visual = visual_info.visual;
   g_depth = visual_info.depth;
   g_colormap =
