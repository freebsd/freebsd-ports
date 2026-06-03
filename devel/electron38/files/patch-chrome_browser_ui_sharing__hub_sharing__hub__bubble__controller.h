--- chrome/browser/ui/sharing_hub/sharing_hub_bubble_controller.h.orig	2024-06-18 21:43:24 UTC
+++ chrome/browser/ui/sharing_hub/sharing_hub_bubble_controller.h
@@ -36,7 +36,7 @@ class SharingHubBubbleController {
   // Returns true if the omnibox icon should be shown.
   virtual bool ShouldOfferOmniboxIcon() = 0;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This method returns the set of first-party actions, which are actions
   // internal to Chrome. Third-party actions (those outside Chrome) are
   // currently not supported.
