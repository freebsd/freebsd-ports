--- chrome/browser/ui/browser_commands.cc.orig	2024-10-16 21:31:02 UTC
+++ chrome/browser/ui/browser_commands.cc
@@ -2036,7 +2036,7 @@ void OpenUpdateChromeDialog(Browser* browser) {
   } else if (UpgradeDetector::GetInstance()->is_outdated_install_no_au()) {
     UpgradeDetector::GetInstance()->NotifyOutdatedInstallNoAutoUpdate();
   } else {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (base::FeatureList::IsEnabled(features::kFewerUpdateConfirmations)) {
       chrome::AttemptRelaunch();
       return;
