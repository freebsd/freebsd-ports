--- components/viz/host/host_display_client.cc.orig	2025-09-10 14:33:47 UTC
+++ components/viz/host/host_display_client.cc
@@ -74,9 +74,9 @@ void HostDisplayClient::AddChildWindowToBrowser(
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
 void HostDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {
-  NOTIMPLEMENTED();
+  NOTREACHED();
 }
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
