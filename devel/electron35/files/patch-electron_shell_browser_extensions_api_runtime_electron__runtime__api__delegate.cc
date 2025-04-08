--- electron/shell/browser/extensions/api/runtime/electron_runtime_api_delegate.cc.orig	2024-10-22 02:29:46 UTC
+++ electron/shell/browser/extensions/api/runtime/electron_runtime_api_delegate.cc
@@ -54,6 +54,8 @@ bool ElectronRuntimeAPIDelegate::GetPlatformInfo(Platf
     info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (strcmp(os, "openbsd") == 0) {
     info->os = extensions::api::runtime::PlatformOs::kOpenbsd;
+  } else if (strcmp(os, "freebsd") == 0) {
+    info->os = extensions::api::runtime::PlatformOs::kFreebsd;
   } else {
     NOTREACHED();
   }
