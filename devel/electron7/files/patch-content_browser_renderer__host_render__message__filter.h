--- content/browser/renderer_host/render_message_filter.h.orig	2019-12-12 12:39:39 UTC
+++ content/browser/renderer_host/render_message_filter.h
@@ -86,14 +86,14 @@ class CONTENT_EXPORT RenderMessageFilter
                               mojom::WidgetPtr widget,
                               CreateFullscreenWidgetCallback callback) override;
   void HasGpuProcess(HasGpuProcessCallback callback) override;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetThreadPriority(int32_t ns_tid,
                          base::ThreadPriority priority) override;
 #endif
 
   void OnResolveProxy(const GURL& url, IPC::Message* reply_msg);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetThreadPriorityOnFileThread(base::PlatformThreadId ns_tid,
                                      base::ThreadPriority priority);
 #endif
