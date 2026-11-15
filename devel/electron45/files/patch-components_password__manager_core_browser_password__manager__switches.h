--- components/password_manager/core/browser/password_manager_switches.h.orig	2025-03-24 20:50:14 UTC
+++ components/password_manager/core/browser/password_manager_switches.h
@@ -9,7 +9,7 @@ namespace password_manager {
 
 namespace password_manager {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kPasswordStore[];
 extern const char kEnableEncryptionSelection[];
 #endif  // BUILDFLAG(IS_LINUX)
