--- extensions/shell/browser/api/runtime/shell_runtime_api_delegate.cc.orig	2025-01-27 17:37:37 UTC
+++ extensions/shell/browser/api/runtime/shell_runtime_api_delegate.cc
@@ -45,7 +45,7 @@ bool ShellRuntimeAPIDelegate::GetPlatformInfo(Platform
 bool ShellRuntimeAPIDelegate::GetPlatformInfo(PlatformInfo* info) {
 #if BUILDFLAG(IS_CHROMEOS)
   info->os = api::runtime::PlatformOs::kCros;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   info->os = api::runtime::PlatformOs::kLinux;
 #endif
   return true;
