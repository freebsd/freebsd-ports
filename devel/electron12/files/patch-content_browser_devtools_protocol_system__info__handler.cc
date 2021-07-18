--- content/browser/devtools/protocol/system_info_handler.cc.orig	2021-04-14 01:08:48 UTC
+++ content/browser/devtools/protocol/system_info_handler.cc
@@ -49,8 +49,8 @@ std::unique_ptr<SystemInfo::Size> GfxSizeToSystemInfoS
 // Linux and Mac Debug builds need more time -- see Issue 796437, 1046598, and
 // 1153667.
 // Windows builds need more time -- see Issue 873112 and 1004472.
-#if ((defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)) && \
-     !defined(NDEBUG)) ||                                              \
+#if ((defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)) && \
+     !defined(NDEBUG)) ||                                                                 \
     defined(OS_WIN)
 const int kGPUInfoWatchdogTimeoutMs = 30000;
 #else
