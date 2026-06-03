--- chrome/common/extensions/extension_constants.h.orig	2026-03-13 16:54:03 UTC
+++ chrome/common/extensions/extension_constants.h
@@ -295,7 +295,7 @@ inline constexpr base::FilePath::CharType
 inline constexpr base::FilePath::CharType
     kReadingModeGDocsHelperManifestFilename[] =
         FILE_PATH_LITERAL("reading_mode_gdocs_helper_manifest.json");
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // The extension id of the google tts engine extension to use on-device natural
 // Google voices.
 inline constexpr char kTTSEngineExtensionId[] =
