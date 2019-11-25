--- electron/atom/common/api/electron_bindings.cc.orig	2019-09-11 17:30:11 UTC
+++ electron/atom/common/api/electron_bindings.cc
@@ -275,7 +275,7 @@ void ElectronBindings::DidReceiveMemoryDump(
     if (base::GetCurrentProcId() == dump.pid()) {
       mate::Dictionary dict = mate::Dictionary::CreateEmpty(isolate);
       const auto& osdump = dump.os_dump();
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
       dict.Set("residentSet", osdump.resident_set_kb);
 #endif
       dict.Set("private", osdump.private_footprint_kb);
