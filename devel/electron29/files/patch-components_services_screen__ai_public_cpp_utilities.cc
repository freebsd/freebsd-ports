--- components/services/screen_ai/public/cpp/utilities.cc.orig	2024-02-21 00:20:42 UTC
+++ components/services/screen_ai/public/cpp/utilities.cc
@@ -32,7 +32,7 @@ constexpr char kScreenAIDlcRootPath[] =
     "/run/imageloader/screen-ai/package/root/";
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr base::FilePath::CharType kScreenAIResourcePathForTests[] =
     FILE_PATH_LITERAL("third_party/screen-ai/linux/resources");
 
@@ -72,7 +72,7 @@ base::FilePath GetLatestComponentBinaryPath() {
 }
 
 base::FilePath GetLatestComponentBinaryPath() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (features::IsScreenAITestModeEnabled()) {
     CHECK_IS_TEST();
     return GetTestComponentBinaryPath();
