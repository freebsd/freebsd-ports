--- chrome/browser/ui/webui/realbox/realbox_handler.cc.orig	2023-10-19 19:58:08 UTC
+++ chrome/browser/ui/webui/realbox/realbox_handler.cc
@@ -146,7 +146,7 @@ constexpr char kMacShareIconResourceName[] =
 #elif BUILDFLAG(IS_WIN)
 constexpr char kWinShareIconResourceName[] =
     "//resources/cr_components/omnibox/icons/win_share.svg";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kLinuxShareIconResourceName[] =
     "//resources/cr_components/omnibox/icons/share.svg";
 #else
@@ -745,7 +745,7 @@ std::string RealboxHandler::PedalVectorIconToResourceN
       icon.name == omnibox::kShareWinChromeRefreshIcon.name) {
     return kWinShareIconResourceName;
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (icon.name == omnibox::kShareIcon.name ||
       icon.name == omnibox::kShareLinuxChromeRefreshIcon.name) {
     return kLinuxShareIconResourceName;
