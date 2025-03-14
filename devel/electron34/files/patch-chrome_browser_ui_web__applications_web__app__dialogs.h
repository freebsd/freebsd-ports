--- chrome/browser/ui/web_applications/web_app_dialogs.h.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/ui/web_applications/web_app_dialogs.h
@@ -21,7 +21,7 @@ static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) |
 #include "ui/gfx/native_widget_types.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-              BUILDFLAG(IS_CHROMEOS));
+              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD));
 
 class GURL;
 class Profile;
