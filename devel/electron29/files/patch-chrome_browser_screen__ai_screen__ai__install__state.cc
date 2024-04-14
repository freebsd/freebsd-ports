--- chrome/browser/screen_ai/screen_ai_install_state.cc.orig	2024-02-21 00:20:35 UTC
+++ chrome/browser/screen_ai/screen_ai_install_state.cc
@@ -23,7 +23,7 @@
 #include "components/services/screen_ai/public/cpp/utilities.h"
 #include "content/public/browser/browser_thread.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/cpu.h"
 #include "base/files/file_util.h"
 #endif
@@ -39,7 +39,7 @@ bool IsDeviceCompatible() {
 bool IsDeviceCompatible() {
   // Check if the CPU has the required instruction set to run the Screen AI
   // library.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!base::CPU().has_sse41()) {
     return false;
   }
@@ -284,7 +284,7 @@ void ScreenAIInstallState::SetComponentFolderForTestin
 
 void ScreenAIInstallState::SetComponentFolderForTesting() {
   CHECK_IS_TEST();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the path to the ScreenAI test files. For more details, see the
   // `screen_ai_test_files` rule in the accessibility_common BUILD file.
   base::FilePath screenai_library_path =
