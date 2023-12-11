--- base/threading/hang_watcher.cc.orig	2023-10-19 19:57:58 UTC
+++ base/threading/hang_watcher.cc
@@ -331,7 +331,7 @@ void HangWatcher::InitializeOnMainThread(ProcessType p
 
   bool enable_hang_watcher = base::FeatureList::IsEnabled(kEnableHangWatcher);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
   if (is_zygote_child) {
     enable_hang_watcher =
         enable_hang_watcher &&
