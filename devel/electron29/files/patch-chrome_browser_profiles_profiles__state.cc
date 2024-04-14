--- chrome/browser/profiles/profiles_state.cc.orig	2024-02-21 00:20:35 UTC
+++ chrome/browser/profiles/profiles_state.cc
@@ -195,7 +195,7 @@ bool IsGuestModeRequested(const base::CommandLine& com
                           PrefService* local_state,
                           bool show_warning) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   DCHECK(local_state);
 
   // Check if guest mode enforcement commandline switch or policy are provided.
