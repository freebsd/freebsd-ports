--- chrome/browser/ui/views/tab_search_bubble_host.cc.orig	2024-06-18 21:43:25 UTC
+++ chrome/browser/ui/views/tab_search_bubble_host.cc
@@ -268,7 +268,7 @@ bool TabSearchBubbleHost::ShouldTabSearchRenderBeforeT
 // Mac should have tabsearch on the right side. Windows >= Win10 has the
 // Tab Search button as a FrameCaptionButton, but it still needs to be on the
 // left if it exists.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return features::IsChromeRefresh2023();
 #else
   return false;
