--- chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc.orig	2026-03-13 16:54:03 UTC
+++ chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc
@@ -26,7 +26,7 @@
 #include "chrome/browser/win/installer_downloader/installer_downloader_pref_names.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_manager.h"  // nogncheck
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_prefs.h"  // nogncheck
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_delegate.h"
@@ -55,7 +55,7 @@ void InfoBarInternalsHandler::GetInfoBars(GetInfoBarsC
 
 void InfoBarInternalsHandler::GetInfoBars(GetInfoBarsCallback callback) {
   std::vector<InfoBarEntryPtr> infobar_list;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   infobar_list.emplace_back(InfoBarEntry::New(
       /*type=*/InfoBarType::kDefaultBrowser, /*name=*/"Default Browser",
       /*description=*/
@@ -94,7 +94,7 @@ bool InfoBarInternalsHandler::TriggerInfoBarInternal(I
 
 bool InfoBarInternalsHandler::TriggerInfoBarInternal(InfoBarType type) {
   switch (type) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kDefaultBrowser: {
       BrowserWindowInterface* const bwi =
           GetLastActiveBrowserWindowInterfaceWithAnyProfile();
