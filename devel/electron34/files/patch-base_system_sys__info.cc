--- base/system/sys_info.cc.orig	2025-01-27 17:37:37 UTC
+++ base/system/sys_info.cc
@@ -229,7 +229,7 @@ void SysInfo::GetHardwareInfo(base::OnceCallback<void(
 #endif
 
 void SysInfo::GetHardwareInfo(base::OnceCallback<void(HardwareInfo)> callback) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   constexpr base::TaskTraits kTraits = {base::MayBlock()};
 #else
   constexpr base::TaskTraits kTraits = {};
