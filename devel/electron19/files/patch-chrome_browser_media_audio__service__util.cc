--- chrome/browser/media/audio_service_util.cc.orig	2022-05-25 04:00:48 UTC
+++ chrome/browser/media/audio_service_util.cc
@@ -21,7 +21,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 bool GetPolicyOrFeature(const char* policy_name, const base::Feature& feature) {
   const policy::PolicyMap& policies =
@@ -40,7 +40,7 @@ bool GetPolicyOrFeature(const char* policy_name, const
 bool IsAudioServiceSandboxEnabled() {
 // TODO(crbug.com/1052397): Remove !IS_CHROMEOS_LACROS once lacros starts being
 // built with OS_CHROMEOS instead of OS_LINUX.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
   return GetPolicyOrFeature(policy::key::kAudioSandboxEnabled,
                             features::kAudioServiceSandbox);
