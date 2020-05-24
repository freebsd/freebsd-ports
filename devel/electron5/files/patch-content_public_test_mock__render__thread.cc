--- content/public/test/mock_render_thread.cc.orig	2019-04-08 08:32:55 UTC
+++ content/public/test/mock_render_thread.cc
@@ -69,7 +69,7 @@ class MockRenderMessageFilterImpl : public mojom::Rend
     std::move(callback).Run(false);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetThreadPriority(int32_t platform_thread_id,
                          base::ThreadPriority thread_priority) override {}
 #endif
