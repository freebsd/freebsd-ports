--- remoting/host/client_session.cc.orig	2026-03-13 16:54:03 UTC
+++ remoting/host/client_session.cc
@@ -194,7 +194,7 @@ void ClientSession::NotifyClientResolution(
   if (effective_policies_.curtain_required.value_or(false)) {
     dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
 #endif
 
