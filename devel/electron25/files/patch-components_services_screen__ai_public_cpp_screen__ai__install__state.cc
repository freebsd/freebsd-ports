--- components/services/screen_ai/public/cpp/screen_ai_install_state.cc.orig	2023-05-25 00:41:52 UTC
+++ components/services/screen_ai/public/cpp/screen_ai_install_state.cc
@@ -17,7 +17,7 @@
 #include "components/services/screen_ai/public/cpp/utilities.h"
 #include "ui/accessibility/accessibility_features.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/cpu.h"
 #endif
 
@@ -31,7 +31,7 @@ namespace {
 bool IsDeviceCompatible() {
   // Check if the CPU has the required instruction set to run the Screen AI
   // library.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!base::CPU().has_sse41()) {
     return false;
   }
