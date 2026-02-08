--- remoting/host/client_session.cc.orig	2026-01-07 00:52:53 UTC
+++ remoting/host/client_session.cc
@@ -195,7 +195,7 @@ void ClientSession::NotifyClientResolution(
   if (effective_policies_.curtain_required.value_or(false)) {
     dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
 #endif
 
