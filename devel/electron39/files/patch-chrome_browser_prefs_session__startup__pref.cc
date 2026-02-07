--- chrome/browser/prefs/session_startup_pref.cc.orig	2025-10-21 20:19:54 UTC
+++ chrome/browser/prefs/session_startup_pref.cc
@@ -71,7 +71,7 @@ SessionStartupPref::Type SessionStartupPref::GetDefaul
 #if BUILDFLAG(IS_CHROMEOS)
   return SessionStartupPref::LAST;
 #else
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (features::kSetDefaultToContinueSession.Get()) {
     return SessionStartupPref::LAST;
   }
