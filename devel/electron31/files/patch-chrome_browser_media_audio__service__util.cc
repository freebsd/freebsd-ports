--- chrome/browser/media/audio_service_util.cc.orig	2024-06-18 21:43:22 UTC
+++ chrome/browser/media/audio_service_util.cc
@@ -21,7 +21,7 @@ namespace {
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 const base::Value* GetPolicy(const char* policy_name) {
   const policy::PolicyMap& policies =
@@ -43,7 +43,7 @@ bool IsAudioServiceSandboxEnabled() {
 bool IsAudioServiceSandboxEnabled() {
 // TODO(crbug.com/40118868): Remove !IS_CHROMEOS_LACROS once lacros starts being
 // built with OS_CHROMEOS instead of OS_LINUX.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
   return GetPolicyOrFeature(policy::key::kAudioSandboxEnabled,
                             features::kAudioServiceSandbox);
