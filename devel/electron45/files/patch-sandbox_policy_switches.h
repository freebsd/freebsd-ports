--- sandbox/policy/switches.h.orig	2026-08-24 20:59:34 UTC
+++ sandbox/policy/switches.h
@@ -25,7 +25,8 @@ SANDBOX_POLICY_EXPORT extern const char kNoSandbox[];
 SANDBOX_POLICY_EXPORT extern const char kGpuSandboxAllowSysVShm[];
 SANDBOX_POLICY_EXPORT extern const char kGpuSandboxFailuresFatal[];
 SANDBOX_POLICY_EXPORT extern const char kNoSandbox[];
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+SANDBOX_POLICY_EXPORT extern const char kDisableUnveil[];
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 SANDBOX_POLICY_EXPORT extern const char kNoZygoteSandbox[];
 #endif
 #if BUILDFLAG(IS_WIN)
