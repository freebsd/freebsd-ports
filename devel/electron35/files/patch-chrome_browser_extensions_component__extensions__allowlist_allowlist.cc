--- chrome/browser/extensions/component_extensions_allowlist/allowlist.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/extensions/component_extensions_allowlist/allowlist.cc
@@ -48,7 +48,7 @@ bool IsComponentExtensionAllowlisted(const std::string
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 #endif  // BUILDFLAG(IS_CHROMEOS)
       extension_misc::kReadingModeGDocsHelperExtensionId,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       extension_misc::kTTSEngineExtensionId,
       extension_misc::kComponentUpdaterTTSEngineExtensionId,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
@@ -85,7 +85,7 @@ bool IsComponentExtensionAllowlisted(int manifest_reso
     case IDR_NETWORK_SPEECH_SYNTHESIS_MANIFEST:
     case IDR_NETWORK_SPEECH_SYNTHESIS_MANIFEST_MV3:
     case IDR_READING_MODE_GDOCS_HELPER_MANIFEST:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case IDR_TTS_ENGINE_MANIFEST:
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
     case IDR_WEBSTORE_MANIFEST:
