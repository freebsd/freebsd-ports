--- content/browser/accessibility/browser_accessibility_state_impl.cc.orig	2025-06-30 07:04:30 UTC
+++ content/browser/accessibility/browser_accessibility_state_impl.cc
@@ -278,7 +278,7 @@ BrowserAccessibilityStateImpl* BrowserAccessibilitySta
 
 // On Android, Mac, Windows and Linux there are platform-specific subclasses.
 #if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_MAC) && \
-    !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+    !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 // static
 std::unique_ptr<BrowserAccessibilityStateImpl>
 BrowserAccessibilityStateImpl::Create() {
