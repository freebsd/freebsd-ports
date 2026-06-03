--- content/utility/utility_blink_platform_with_sandbox_support_impl.h.orig	2025-03-24 20:50:14 UTC
+++ content/utility/utility_blink_platform_with_sandbox_support_impl.h
@@ -34,7 +34,7 @@ class UtilityBlinkPlatformWithSandboxSupportImpl : pub
 
  private:
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 };
