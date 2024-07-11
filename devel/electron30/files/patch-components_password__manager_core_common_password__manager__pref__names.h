--- components/password_manager/core/common/password_manager_pref_names.h.orig	2024-04-15 20:33:55 UTC
+++ components/password_manager/core/common/password_manager_pref_names.h
@@ -332,7 +332,7 @@ inline constexpr char kPasswordSharingEnabled[] =
 inline constexpr char kPasswordSharingEnabled[] =
     "password_manager.password_sharing_enabled";
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Integer pref indicating how many times relaunch Chrome bubble was dismissed.
 inline constexpr char kRelaunchChromeBubbleDismissedCounter[] =
     "password_manager.relaunch_chrome_bubble_dismissed_counter";
