--- chrome/browser/media/audio_service_util.cc.orig	2021-07-15 19:13:33 UTC
+++ chrome/browser/media/audio_service_util.cc
@@ -21,7 +21,7 @@
 namespace {
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 bool GetPolicyOrFeature(const char* policy_name, const base::Feature& feature) {
   const policy::PolicyMap& policies =
       g_browser_process->browser_policy_connector()
@@ -43,7 +43,7 @@ bool IsAudioServiceSandboxEnabled() {
 // TODO(crbug.com/1052397): Remove !IS_CHROMEOS_LACROS once lacros starts being
 // built with OS_CHROMEOS instead of OS_LINUX.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   return GetPolicyOrFeature(policy::key::kAudioSandboxEnabled,
                             features::kAudioServiceSandbox);
 #else
