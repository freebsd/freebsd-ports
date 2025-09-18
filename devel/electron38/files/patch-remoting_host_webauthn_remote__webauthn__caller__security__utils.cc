--- remoting/host/webauthn/remote_webauthn_caller_security_utils.cc.orig	2025-06-30 07:04:30 UTC
+++ remoting/host/webauthn/remote_webauthn_caller_security_utils.cc
@@ -14,7 +14,7 @@
 #include "base/strings/utf_string_conversions.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "base/containers/fixed_flat_set.h"
 #include "base/files/file_path.h"
 #include "remoting/host/base/process_util.h"
@@ -48,7 +48,7 @@ namespace {
 
 // No static variables needed for debug builds.
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 constexpr auto kAllowedCallerPrograms =
     base::MakeFixedFlatSet<base::FilePath::StringViewType>({
@@ -99,7 +99,7 @@ bool IsLaunchedByTrustedProcess() {
 #if !defined(NDEBUG)
   // Just return true on debug builds for the convenience of development.
   return true;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ProcessId parent_pid =
       base::GetParentProcessId(base::GetCurrentProcessHandle());
   // Note that on Linux the process image may no longer exist in its original
