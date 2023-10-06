--- chrome/browser/chrome_process_singleton.cc.orig	2023-08-10 01:48:34 UTC
+++ chrome/browser/chrome_process_singleton.cc
@@ -11,7 +11,7 @@
 #include "chrome/browser/metrics/chrome_metrics_service_accessor.h"
 #include "chrome/common/chrome_switches.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/hash/hash.h"
 #include "chrome/common/channel_info.h"
 #include "components/version_info/channel.h"
@@ -22,7 +22,7 @@
 #include "base/win/registry.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #endif
 
@@ -33,14 +33,14 @@ constexpr char kEarlySingletonEnabledGroup[] = "Enable
 constexpr char kEarlySingletonDisabledMergeGroup[] = "Disabled_Merge3";
 constexpr char kEarlySingletonDefaultGroup[] = "Default3";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kEarlySingletonDisabledGroup[] = "Disabled3";
 #endif  // BUILDFLAG(IS_WIN)
 
 const char* g_early_singleton_feature_group_ = nullptr;
 ChromeProcessSingleton* g_chrome_process_singleton_ = nullptr;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 std::string GetMachineGUID() {
   std::string machine_guid;
@@ -171,7 +171,7 @@ void ChromeProcessSingleton::SetupEarlySingletonFeatur
     return;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   g_early_singleton_feature_group_ = EnrollMachineInEarlySingletonFeature();
 #else
   g_early_singleton_feature_group_ = kEarlySingletonDefaultGroup;
