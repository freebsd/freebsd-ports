--- electron/atom/common/api/atom_bindings.cc.orig	2019-12-19 06:08:26 UTC
+++ electron/atom/common/api/atom_bindings.cc
@@ -273,7 +273,7 @@ void AtomBindings::DidReceiveMemoryDump(
     if (base::GetCurrentProcId() == dump.pid()) {
       mate::Dictionary dict = mate::Dictionary::CreateEmpty(isolate);
       const auto& osdump = dump.os_dump();
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
       dict.Set("residentSet", osdump.resident_set_kb);
 #endif
       dict.Set("private", osdump.private_footprint_kb);
