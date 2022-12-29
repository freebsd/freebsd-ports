--- chrome/browser/process_singleton_posix.cc.orig	2022-08-31 12:19:35 UTC
+++ chrome/browser/process_singleton_posix.cc
@@ -99,7 +99,7 @@
 #include "ui/base/l10n/l10n_util.h"
 
 #if 0
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/process_singleton_dialog_linux.h"
 #endif
 #endif
@@ -357,7 +357,7 @@ bool DisplayProfileInUseError(const base::FilePath& lo
   if (g_disable_prompt)
     return g_user_opted_unlock_in_use_profile;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::u16string relaunch_button_text =
       l10n_util::GetStringUTF16(IDS_PROFILE_IN_USE_LINUX_RELAUNCH);
   return ShowProcessSingletonDialog(error, relaunch_button_text);
