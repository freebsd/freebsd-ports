--- services/screen_ai/public/cpp/utilities.cc.orig	2025-06-30 07:04:30 UTC
+++ services/screen_ai/public/cpp/utilities.cc
@@ -21,7 +21,7 @@ constexpr uint32_t kMaxImageDimensionForOcr = 2048;
 // The maximum image dimension which is processed without downsampling by OCR.
 constexpr uint32_t kMaxImageDimensionForOcr = 2048;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr char kBinaryPathSwitch[] = "screen-ai-binary";
 #endif
 
@@ -42,7 +42,7 @@ constexpr char kScreenAIDlcRootPath[] =
 #endif
 
 #if BUILDFLAG(ENABLE_SCREEN_AI_BROWSERTESTS)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr base::FilePath::CharType kScreenAIResourcePathForTests[] =
     FILE_PATH_LITERAL("third_party/screen-ai/linux/resources");
 #elif BUILDFLAG(IS_MAC)
@@ -131,7 +131,7 @@ const char* GetBinaryPathSwitch() {
 
 const char* GetBinaryPathSwitch() {
   // This is only used on Linux and ChromeOS.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return kBinaryPathSwitch;
 #else
   return nullptr;
