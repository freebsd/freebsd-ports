--- chrome/browser/web_applications/web_app_install_info.h.orig	2024-06-18 21:43:25 UTC
+++ chrome/browser/web_applications/web_app_install_info.h
@@ -35,7 +35,7 @@ static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) |
 #include "url/gurl.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-              BUILDFLAG(IS_CHROMEOS));
+              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD));
 
 namespace web_app {
 
