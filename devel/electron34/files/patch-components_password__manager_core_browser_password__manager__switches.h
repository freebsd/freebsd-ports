--- components/password_manager/core/browser/password_manager_switches.h.orig	2024-08-14 20:54:51 UTC
+++ components/password_manager/core/browser/password_manager_switches.h
@@ -10,7 +10,7 @@ namespace password_manager {
 
 namespace password_manager {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kPasswordStore[];
 extern const char kEnableEncryptionSelection[];
 #endif  // BUILDFLAG(IS_LINUX)
