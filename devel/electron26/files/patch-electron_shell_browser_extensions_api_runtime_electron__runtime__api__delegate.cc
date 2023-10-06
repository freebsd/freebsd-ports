--- electron/shell/browser/extensions/api/runtime/electron_runtime_api_delegate.cc.orig	2023-08-09 14:05:20 UTC
+++ electron/shell/browser/extensions/api/runtime/electron_runtime_api_delegate.cc
@@ -55,6 +55,8 @@ bool ElectronRuntimeAPIDelegate::GetPlatformInfo(Platf
     info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (strcmp(os, "openbsd") == 0) {
     info->os = extensions::api::runtime::PlatformOs::kOpenbsd;
+  } else if (strcmp(os, "freebsd") == 0) {
+    info->os = extensions::api::runtime::PlatformOs::kFreebsd;
   } else {
     NOTREACHED();
     return false;
