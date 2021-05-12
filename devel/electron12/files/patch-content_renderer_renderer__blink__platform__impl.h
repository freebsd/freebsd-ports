--- content/renderer/renderer_blink_platform_impl.h.orig	2021-04-22 07:51:51 UTC
+++ content/renderer/renderer_blink_platform_impl.h
@@ -29,7 +29,7 @@
 #include "third_party/blink/public/mojom/cache_storage/cache_storage.mojom.h"
 #include "third_party/blink/public/mojom/loader/code_cache.mojom.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"  // nogncheck
 #include "third_party/skia/include/core/SkRefCnt.h"           // nogncheck
 #endif
@@ -183,7 +183,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
       const blink::WebURL& top_document_web_url) override;
   gpu::GpuMemoryBufferManager* GetGpuMemoryBufferManager() override;
   blink::WebString ConvertIDNToUnicode(const blink::WebString& host) override;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   void SetDisplayThreadPriority(base::PlatformThreadId thread_id) override;
 #endif
   blink::BlameContext* GetTopLevelBlameContext() override;
@@ -231,7 +231,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
   // Return the mojo interface for making CodeCache calls.
   blink::mojom::CodeCacheHost& GetCodeCacheHost();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
@@ -252,7 +252,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
   mojo::PendingRemote<blink::mojom::CodeCacheHost> code_cache_host_remote_;
   mojo::SharedRemote<blink::mojom::CodeCacheHost> code_cache_host_;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
