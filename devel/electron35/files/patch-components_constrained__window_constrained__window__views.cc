--- components/constrained_window/constrained_window_views.cc.orig	2025-03-24 20:50:14 UTC
+++ components/constrained_window/constrained_window_views.cc
@@ -375,7 +375,7 @@ bool PlatformClipsChildrenToViewport() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
