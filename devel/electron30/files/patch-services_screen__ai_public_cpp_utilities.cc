--- services/screen_ai/public/cpp/utilities.cc.orig	2024-04-15 20:34:03 UTC
+++ services/screen_ai/public/cpp/utilities.cc
@@ -19,7 +19,7 @@ namespace {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr char kBinaryPathSwitch[] = "screen-ai-binary";
 #endif
 
@@ -40,7 +40,7 @@ constexpr char kScreenAIDlcRootPath[] =
 #endif
 
 #if BUILDFLAG(ENABLE_SCREEN_AI_BROWSERTESTS)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr base::FilePath::CharType kScreenAIResourcePathForTests[] =
     FILE_PATH_LITERAL("third_party/screen-ai/linux/resources");
 #elif BUILDFLAG(IS_MAC)
@@ -127,7 +127,7 @@ const char* GetBinaryPathSwitch() {
 
 const char* GetBinaryPathSwitch() {
   // This is only used on Linux and ChromeOS.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return kBinaryPathSwitch;
 #else
   return nullptr;
