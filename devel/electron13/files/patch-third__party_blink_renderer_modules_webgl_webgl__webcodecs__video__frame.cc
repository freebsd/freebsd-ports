--- third_party/blink/renderer/modules/webgl/webgl_webcodecs_video_frame.cc.orig	2021-07-15 19:13:46 UTC
+++ third_party/blink/renderer/modules/webgl/webgl_webcodecs_video_frame.cc
@@ -278,7 +278,7 @@ WebGLExtensionName WebGLWebCodecsVideoFrame::GetName()
 bool WebGLWebCodecsVideoFrame::Supported(WebGLRenderingContextBase* context) {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(jie.a.chen@intel.com): Add Linux support.
   return false;
 #else
