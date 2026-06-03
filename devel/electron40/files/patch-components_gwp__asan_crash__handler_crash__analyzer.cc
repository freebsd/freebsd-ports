--- components/gwp_asan/crash_handler/crash_analyzer.cc.orig	2026-01-07 00:52:53 UTC
+++ components/gwp_asan/crash_handler/crash_analyzer.cc
@@ -36,7 +36,7 @@
 #include "third_party/crashpad/crashpad/snapshot/process_snapshot.h"
 #include "third_party/crashpad/crashpad/util/process/process_memory.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include <signal.h>
 #elif BUILDFLAG(IS_APPLE)
 #include <mach/exception_types.h>
@@ -114,7 +114,7 @@ crashpad::VMAddress CrashAnalyzer::GetAccessAddress(
 
 crashpad::VMAddress CrashAnalyzer::GetAccessAddress(
     const crashpad::ExceptionSnapshot& exception) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (exception.Exception() == SIGSEGV || exception.Exception() == SIGBUS)
     return exception.ExceptionAddress();
 #elif BUILDFLAG(IS_APPLE)
