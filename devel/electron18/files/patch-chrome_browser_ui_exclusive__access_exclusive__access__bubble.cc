--- chrome/browser/ui/exclusive_access/exclusive_access_bubble.cc.orig	2022-05-19 03:45:18 UTC
+++ chrome/browser/ui/exclusive_access/exclusive_access_bubble.cc
@@ -16,7 +16,7 @@
 
 // NOTE(koz): Linux doesn't use the thick shadowed border, so we add padding
 // here.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const int ExclusiveAccessBubble::kPaddingPx = 8;
 #else
 const int ExclusiveAccessBubble::kPaddingPx = 15;
