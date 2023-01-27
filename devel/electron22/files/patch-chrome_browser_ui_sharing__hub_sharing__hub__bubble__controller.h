--- chrome/browser/ui/sharing_hub/sharing_hub_bubble_controller.h.orig	2022-08-31 12:19:35 UTC
+++ chrome/browser/ui/sharing_hub/sharing_hub_bubble_controller.h
@@ -37,7 +37,7 @@ class SharingHubBubbleController {
   virtual bool ShouldOfferOmniboxIcon() = 0;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // These two methods return the sets of first- and third-party actions;
   // first-party actions are internal to Chrome and third-party actions are
   // other websites or apps.
