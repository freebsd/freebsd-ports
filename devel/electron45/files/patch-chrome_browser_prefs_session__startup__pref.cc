--- chrome/browser/prefs/session_startup_pref.cc.orig	2026-10-19 21:50:55 UTC
+++ chrome/browser/prefs/session_startup_pref.cc
@@ -66,7 +66,7 @@ SessionStartupPref::Type SessionStartupPref::GetDefaul
 #if BUILDFLAG(IS_CHROMEOS)
   return SessionStartupPref::LAST;
 #else
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (features::kSetDefaultToContinueSession.Get()) {
     return SessionStartupPref::LAST;
   }
