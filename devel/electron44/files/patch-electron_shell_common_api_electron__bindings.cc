--- electron/shell/common/api/electron_bindings.cc.orig	2026-08-31 00:54:19 UTC
+++ electron/shell/common/api/electron_bindings.cc
@@ -185,7 +185,7 @@ v8::Local<v8::Value> ElectronBindings::GetSystemMemory
 #endif
   dict.Set("free", free.InKiB());
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   dict.Set("available", mem_info.available.InKiB());
 #endif
 
@@ -257,7 +257,7 @@ void ElectronBindings::DidReceiveMemoryDump(
     if (target_pid == dump.pid()) {
       auto dict = gin_helper::Dictionary::CreateEmpty(isolate);
       const auto& osdump = dump.os_dump();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       dict.Set("residentSet", osdump.resident_set_kb);
 #endif
       dict.Set("private", osdump.private_footprint_kb);
