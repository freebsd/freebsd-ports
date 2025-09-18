--- chrome/enterprise_companion/lock.cc.orig	2024-08-14 20:54:42 UTC
+++ chrome/enterprise_companion/lock.cc
@@ -17,7 +17,7 @@ namespace {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kLockName[] = "/" PRODUCT_FULLNAME_STRING ".lock";
 #elif BUILDFLAG(IS_MAC)
 constexpr char kLockName[] = MAC_BUNDLE_IDENTIFIER_STRING ".lock";
@@ -42,7 +42,7 @@ std::unique_ptr<ScopedLock> CreateScopedLock(base::Tim
 namespace enterprise_companion {
 
 std::unique_ptr<ScopedLock> CreateScopedLock(base::TimeDelta timeout) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return named_system_lock::ScopedLock::Create(kLockName, timeout);
 #elif BUILDFLAG(IS_WIN)
   CSecurityAttributes sa =
