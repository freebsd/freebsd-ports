--- content/browser/renderer_host/render_message_filter.h.orig	2019-03-15 06:37:20 UTC
+++ content/browser/renderer_host/render_message_filter.h
@@ -110,14 +110,14 @@ class CONTENT_EXPORT RenderMessageFilter
       const url::Origin& cache_storage_origin,
       const std::string& cache_storage_cache_name) override;
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
