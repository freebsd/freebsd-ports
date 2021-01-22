--- ui/compositor/compositor.cc.orig	2021-01-11 02:45:07 UTC
+++ ui/compositor/compositor.cc
@@ -705,7 +705,7 @@ void Compositor::OnFrameTokenChanged(uint32_t frame_to
   NOTREACHED();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 void Compositor::OnCompleteSwapWithNewSize(const gfx::Size& size) {
   for (auto& observer : observer_list_)
     observer.OnCompositingCompleteSwapWithNewSize(this, size);
