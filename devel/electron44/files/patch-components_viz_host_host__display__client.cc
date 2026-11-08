--- components/viz/host/host_display_client.cc.orig	2026-05-12 08:53:52 UTC
+++ components/viz/host/host_display_client.cc
@@ -75,7 +75,7 @@ void HostDisplayClient::AddChildWindowToBrowser(
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
 void HostDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {
   NOTIMPLEMENTED();
 }
