--- components/flags_ui/flags_state.cc.orig	2022-05-11 07:16:50 UTC
+++ components/flags_ui/flags_state.cc
@@ -654,7 +654,7 @@ unsigned short FlagsState::GetCurrentPlatform() {
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   return kOsCrOS;
 #elif (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    defined(OS_OPENBSD)
+    defined(OS_BSD)
   return kOsLinux;
 #elif defined(OS_ANDROID)
   return kOsAndroid;
