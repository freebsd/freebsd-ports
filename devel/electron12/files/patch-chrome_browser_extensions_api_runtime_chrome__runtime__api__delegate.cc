--- chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2021-04-14 01:08:39 UTC
+++ chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -286,6 +286,8 @@ bool ChromeRuntimeAPIDelegate::GetPlatformInfo(Platfor
     info->os = extensions::api::runtime::PLATFORM_OS_CROS;
   } else if (strcmp(os, "linux") == 0) {
     info->os = extensions::api::runtime::PLATFORM_OS_LINUX;
+  } else if (strcmp(os, "freebsd") == 0) {
+    info->os = extensions::api::runtime::PLATFORM_OS_FREEBSD;
   } else if (strcmp(os, "openbsd") == 0) {
     info->os = extensions::api::runtime::PLATFORM_OS_OPENBSD;
   } else {
