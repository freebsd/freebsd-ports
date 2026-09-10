--- components/constrained_window/constrained_window_views.cc.orig	2026-08-24 20:59:34 UTC
+++ components/constrained_window/constrained_window_views.cc
@@ -419,7 +419,7 @@ bool PlatformClipsChildrenToViewport() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
