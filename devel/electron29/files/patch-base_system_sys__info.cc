--- base/system/sys_info.cc.orig	2023-11-29 21:39:40 UTC
+++ base/system/sys_info.cc
@@ -225,7 +225,7 @@ void SysInfo::GetHardwareInfo(base::OnceCallback<void(
 #endif
 
 void SysInfo::GetHardwareInfo(base::OnceCallback<void(HardwareInfo)> callback) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   constexpr base::TaskTraits kTraits = {base::MayBlock()};
 #else
   constexpr base::TaskTraits kTraits = {};
