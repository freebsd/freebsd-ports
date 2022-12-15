--- content/browser/devtools/protocol/system_info_handler.cc.orig	2022-02-28 16:54:41 UTC
+++ content/browser/devtools/protocol/system_info_handler.cc
@@ -50,7 +50,7 @@ std::unique_ptr<SystemInfo::Size> GfxSizeToSystemInfoS
 // Windows builds need more time -- see Issue 873112 and 1004472.
 // Mac builds need more time - see Issue angleproject:6182.
 #if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !defined(NDEBUG)) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || defined(USE_OZONE)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || defined(USE_OZONE) || BUILDFLAG(IS_BSD)
 static constexpr int kGPUInfoWatchdogTimeoutMultiplierOS = 3;
 #else
 static constexpr int kGPUInfoWatchdogTimeoutMultiplierOS = 1;
