--- chrome/browser/process_singleton_posix.cc.orig	2023-01-30 07:58:59 UTC
+++ chrome/browser/process_singleton_posix.cc
@@ -357,7 +357,7 @@ bool DisplayProfileInUseError(const base::FilePath& lo
   if (g_disable_prompt)
     return g_user_opted_unlock_in_use_profile;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::u16string relaunch_button_text =
       l10n_util::GetStringUTF16(IDS_PROFILE_IN_USE_LINUX_RELAUNCH);
   return ShowProcessSingletonDialog(error, relaunch_button_text);
