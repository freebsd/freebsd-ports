--- components/constrained_window/constrained_window_views.cc.orig	2025-06-30 07:04:30 UTC
+++ components/constrained_window/constrained_window_views.cc
@@ -392,7 +392,7 @@ bool PlatformClipsChildrenToViewport() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
