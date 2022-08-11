--- content/renderer/media/render_media_client.cc.orig	2022-06-10 05:36:16 UTC
+++ content/renderer/media/render_media_client.cc
@@ -21,7 +21,7 @@ namespace {
 // it asynchronously ahead of time, but can fallback to a blocking call
 // when it's needed synchronously.
 #if BUILDFLAG(ENABLE_PLATFORM_HEVC) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #define NEEDS_PROFILE_UPDATER 1
 #else
 #define NEEDS_PROFILE_UPDATER 0
