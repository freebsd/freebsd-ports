--- third_party/blink/renderer/platform/graphics/begin_frame_provider.cc.orig	2025-06-30 07:04:30 UTC
+++ third_party/blink/renderer/platform/graphics/begin_frame_provider.cc
@@ -70,8 +70,12 @@ void BeginFrameProvider::CreateCompositorFrameSinkIfNe
 
   // Once we are using RAF, this thread is driving user interactive display
   // updates. Update priority accordingly.
+  // pledge(2)
+  // stop this baloney
+#if !defined(OS_OPENBSD)
   base::PlatformThread::SetCurrentThreadType(
       base::ThreadType::kDisplayCritical);
+#endif
 
   mojo::Remote<mojom::blink::EmbeddedFrameSinkProvider> provider;
   Platform::Current()->GetBrowserInterfaceBroker()->GetInterface(
