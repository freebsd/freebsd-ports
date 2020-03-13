--- content/browser/renderer_host/render_message_filter.cc.orig	2019-12-12 12:39:39 UTC
+++ content/browser/renderer_host/render_message_filter.cc
@@ -70,7 +70,7 @@
 #if defined(OS_MACOSX)
 #include "ui/accelerated_widget_mac/window_resize_helper_mac.h"
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/linux_util.h"
 #include "base/threading/platform_thread.h"
 #endif
@@ -148,7 +148,7 @@ void RenderMessageFilter::CreateFullscreenWidget(
   std::move(callback).Run(route_id);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void RenderMessageFilter::SetThreadPriorityOnFileThread(
     base::PlatformThreadId ns_tid,
     base::ThreadPriority priority) {
@@ -169,7 +169,7 @@ void RenderMessageFilter::SetThreadPriorityOnFileThrea
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void RenderMessageFilter::SetThreadPriority(int32_t ns_tid,
                                             base::ThreadPriority priority) {
   constexpr base::TaskTraits kTraits = {
