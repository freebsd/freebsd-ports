--- electron/shell/common/api/electron_bindings.cc.orig	2019-12-13 19:48:14 UTC
+++ electron/shell/common/api/electron_bindings.cc
@@ -288,7 +288,7 @@ void ElectronBindings::DidReceiveMemoryDump(
     if (base::GetCurrentProcId() == dump.pid()) {
       mate::Dictionary dict = mate::Dictionary::CreateEmpty(isolate);
       const auto& osdump = dump.os_dump();
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
       dict.Set("residentSet", osdump.resident_set_kb);
 #endif
       dict.Set("private", osdump.private_footprint_kb);
