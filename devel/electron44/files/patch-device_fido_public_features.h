--- device/fido/public/features.h.orig	2026-06-23 23:37:18 UTC
+++ device/fido/public/features.h
@@ -14,7 +14,7 @@ namespace device {
 namespace device {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Allows the passkey unlock error UI to be shown.
 COMPONENT_EXPORT(FIDO_PUBLIC)
 BASE_DECLARE_FEATURE(kPasskeyUnlockErrorUi);
