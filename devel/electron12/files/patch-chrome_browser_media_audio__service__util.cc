--- chrome/browser/media/audio_service_util.cc.orig	2021-04-14 01:08:40 UTC
+++ chrome/browser/media/audio_service_util.cc
@@ -24,7 +24,7 @@ bool IsAudioServiceSandboxEnabled() {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   const policy::PolicyMap& policies =
       g_browser_process->browser_policy_connector()
           ->GetPolicyService()
