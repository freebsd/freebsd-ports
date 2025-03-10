--- components/soda/soda_util.cc.orig	2024-06-18 21:43:30 UTC
+++ components/soda/soda_util.cc
@@ -20,7 +20,7 @@
 #include "base/win/windows_version.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_X86_FAMILY)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_FAMILY)
 #include "base/cpu.h"
 #endif
 
@@ -45,7 +45,7 @@ bool IsSupportedChromeOS() {
 }
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsSupportedLinux() {
 #if defined(ARCH_CPU_X86_FAMILY)
   // Check if the CPU has the required instruction set to run the Speech
@@ -76,7 +76,7 @@ bool IsOnDeviceSpeechRecognitionSupported() {
 bool IsOnDeviceSpeechRecognitionSupported() {
 #if BUILDFLAG(IS_CHROMEOS)
   return IsSupportedChromeOS();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return IsSupportedLinux();
 #elif BUILDFLAG(IS_WIN)
   return IsSupportedWin();
