--- chrome/browser/extensions/api/messaging/native_process_launcher_posix.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/extensions/api/messaging/native_process_launcher_posix.cc
@@ -82,7 +82,7 @@ bool NativeProcessLauncher::LaunchNativeProcess(
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Don't use no_new_privs mode, e.g. in case the host needs to use sudo.
   options.allow_new_privs = true;
 #endif
