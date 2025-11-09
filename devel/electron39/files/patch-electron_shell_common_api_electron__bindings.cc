--- electron/shell/common/api/electron_bindings.cc.orig	2025-09-02 20:56:04 UTC
+++ electron/shell/common/api/electron_bindings.cc
@@ -255,7 +255,7 @@ void ElectronBindings::DidReceiveMemoryDump(
     if (target_pid == dump.pid()) {
       auto dict = gin_helper::Dictionary::CreateEmpty(isolate);
       const auto& osdump = dump.os_dump();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       dict.Set("residentSet", osdump.resident_set_kb);
 #endif
       dict.Set("private", osdump.private_footprint_kb);
