--- content/browser/renderer_host/delegated_frame_host.cc.orig	2024-02-21 00:20:45 UTC
+++ content/browser/renderer_host/delegated_frame_host.cc
@@ -317,7 +317,7 @@ void DelegatedFrameHost::EmbedSurface(
 
   if (!primary_surface_id ||
       primary_surface_id->local_surface_id() != local_surface_id_) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     // On Windows and Linux, we would like to produce new content as soon as
     // possible or the OS will create an additional black gutter. Until we can
     // block resize on surface synchronization on these platforms, we will not
