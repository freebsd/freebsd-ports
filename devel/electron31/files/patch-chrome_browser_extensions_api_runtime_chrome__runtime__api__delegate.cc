--- chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2024-06-18 21:43:22 UTC
+++ chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -284,7 +284,9 @@ bool ChromeRuntimeAPIDelegate::GetPlatformInfo(Platfor
   } else if (strcmp(os, "linux") == 0) {
     info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (strcmp(os, "openbsd") == 0) {
-    info->os = extensions::api::runtime::PlatformOs::kOpenbsd;
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
+  } else if (strcmp(os, "freebsd") == 0) {
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else {
     NOTREACHED() << "Platform not supported: " << os;
     return false;
