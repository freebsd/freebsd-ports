--- content/renderer/media/render_media_client.cc.orig	2022-10-24 13:33:33 UTC
+++ content/renderer/media/render_media_client.cc
@@ -22,7 +22,7 @@ namespace {
 // when it's needed synchronously.
 #if BUILDFLAG(ENABLE_PLATFORM_HEVC) &&                                     \
     (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || \
-     BUILDFLAG(IS_MAC))
+     BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD))
 #define NEEDS_PROFILE_UPDATER 1
 #else
 #define NEEDS_PROFILE_UPDATER 0
