--- chrome/browser/ui/web_applications/web_app_dialogs.h.orig	2024-06-18 21:43:25 UTC
+++ chrome/browser/ui/web_applications/web_app_dialogs.h
@@ -22,7 +22,7 @@ static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) |
 #include "ui/gfx/native_widget_types.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-              BUILDFLAG(IS_CHROMEOS));
+              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD));
 
 class GURL;
 class Profile;
