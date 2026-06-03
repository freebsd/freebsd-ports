--- chrome/common/extensions/extension_constants.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/common/extensions/extension_constants.cc
@@ -38,7 +38,7 @@ const char* const kBuiltInFirstPartyExtensionIds[] = {
     kGoogleSpeechSynthesisExtensionId,
 #endif  // BUILDFLAG(IS_CHROMEOS)
     kReadingModeGDocsHelperExtensionId,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     kTTSEngineExtensionId,
     kComponentUpdaterTTSEngineExtensionId,
 #endif        // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
