--- content/browser/renderer_host/render_message_filter.cc.orig	2022-08-31 12:19:35 UTC
+++ content/browser/renderer_host/render_message_filter.cc
@@ -66,7 +66,7 @@
 #if BUILDFLAG(IS_MAC)
 #include "ui/accelerated_widget_mac/window_resize_helper_mac.h"
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/linux_util.h"
 #include "base/threading/platform_thread.h"
 #endif
@@ -128,7 +128,7 @@ void RenderMessageFilter::GenerateFrameRoutingID(
   std::move(callback).Run(routing_id, frame_token, devtools_frame_token);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void RenderMessageFilter::SetThreadTypeOnWorkerThread(
     base::PlatformThreadId ns_tid,
     base::ThreadType thread_type) {
@@ -149,7 +149,7 @@ void RenderMessageFilter::SetThreadTypeOnWorkerThread(
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void RenderMessageFilter::SetThreadType(int32_t ns_tid,
                                         base::ThreadType thread_type) {
   constexpr base::TaskTraits kTraits = {
