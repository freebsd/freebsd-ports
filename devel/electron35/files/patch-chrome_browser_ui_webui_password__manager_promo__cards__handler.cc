--- chrome/browser/ui/webui/password_manager/promo_cards_handler.cc.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/ui/webui/password_manager/promo_cards_handler.cc
@@ -28,7 +28,7 @@
 #include "chrome/browser/ui/webui/password_manager/promo_cards/web_password_manager_promo.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/password_manager/promo_cards/relaunch_chrome_promo.h"
 #endif
 
@@ -71,7 +71,7 @@ std::vector<std::unique_ptr<PasswordPromoCardBase>> Ge
           .get()));
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   promo_cards.push_back(
       std::make_unique<RelaunchChromePromo>(profile->GetPrefs()));
 #endif
