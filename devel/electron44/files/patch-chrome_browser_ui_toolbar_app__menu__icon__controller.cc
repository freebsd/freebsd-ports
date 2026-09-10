--- chrome/browser/ui/toolbar/app_menu_icon_controller.cc.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/ui/toolbar/app_menu_icon_controller.cc
@@ -166,7 +166,7 @@ std::u16string AppMenuIconController::GetIconLabel(Ico
     return std::u16string();
   } else if (type == IconType::kUpgradeNotification) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
     int message_id = IDS_APP_MENU_BUTTON_UPDATE;
     // Select an update text option randomly. Show this text in all browser
     // windows.
