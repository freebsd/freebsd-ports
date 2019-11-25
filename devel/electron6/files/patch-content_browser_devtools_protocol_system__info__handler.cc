--- content/browser/devtools/protocol/system_info_handler.cc.orig	2019-09-10 11:14:00 UTC
+++ content/browser/devtools/protocol/system_info_handler.cc
@@ -40,7 +40,7 @@ using GetInfoCallback = SystemInfo::Backend::GetInfoCa
 // Give the GPU process a few seconds to provide GPU info.
 // Linux Debug builds need more time -- see Issue 796437.
 // Windows builds need more time -- see Issue 873112.
-#if (defined(OS_LINUX) && !defined(NDEBUG)) || defined(OS_WIN)
+#if ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(NDEBUG)) || defined(OS_WIN)
 const int kGPUInfoWatchdogTimeoutMs = 20000;
 #else
 const int kGPUInfoWatchdogTimeoutMs = 5000;
