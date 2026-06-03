--- third_party/blink/renderer/platform/graphics/begin_frame_provider.cc.orig	2026-03-13 16:54:03 UTC
+++ third_party/blink/renderer/platform/graphics/begin_frame_provider.cc
@@ -71,7 +71,11 @@ void BeginFrameProvider::CreateCompositorFrameSinkIfNe
 
   // Once we are using RAF, this thread is driving user interactive display
   // updates. Update priority accordingly.
+  // pledge(2)
+  // stop this baloney
+#if !defined(OS_OPENBSD)
   base::PlatformThread::SetCurrentThreadType(base::ThreadType::kPresentation);
+#endif
 
   mojo::Remote<mojom::blink::EmbeddedFrameSinkProvider> provider;
   Platform::Current()->GetBrowserInterfaceBroker()->GetInterface(
