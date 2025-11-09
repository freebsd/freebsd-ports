--- components/services/paint_preview_compositor/paint_preview_compositor_collection_impl.cc.orig	2024-02-21 00:20:42 UTC
+++ components/services/paint_preview_compositor/paint_preview_compositor_collection_impl.cc
@@ -22,7 +22,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "content/public/child/dwrite_font_proxy_init_win.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #endif
 
@@ -79,7 +79,7 @@ PaintPreviewCompositorCollectionImpl::PaintPreviewComp
     // Initialize font access for Skia.
 #if BUILDFLAG(IS_WIN)
   content::InitializeDWriteFontProxy();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   mojo::PendingRemote<font_service::mojom::FontService> font_service;
   content::UtilityThread::Get()->BindHostReceiver(
       font_service.InitWithNewPipeAndPassReceiver());
@@ -102,7 +102,7 @@ PaintPreviewCompositorCollectionImpl::PaintPreviewComp
                              base::BindOnce([] { skia::DefaultFontMgr(); }));
 
   // Sanity check that fonts are working.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // No WebSandbox is provided on Linux so the local fonts aren't accessible.
   // This is fine since since the subsetted fonts are provided in the SkPicture.
   // However, we still need to check that the SkFontMgr starts as it is used by
