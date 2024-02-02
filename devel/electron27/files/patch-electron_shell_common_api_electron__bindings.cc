--- electron/shell/common/api/electron_bindings.cc.orig	2024-01-29 17:52:10 UTC
+++ electron/shell/common/api/electron_bindings.cc
@@ -260,7 +260,7 @@ void ElectronBindings::DidReceiveMemoryDump(
     if (target_pid == dump.pid()) {
       gin_helper::Dictionary dict = gin::Dictionary::CreateEmpty(isolate);
       const auto& osdump = dump.os_dump();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       dict.Set("residentSet", osdump.resident_set_kb);
 #endif
       dict.Set("private", osdump.private_footprint_kb);
