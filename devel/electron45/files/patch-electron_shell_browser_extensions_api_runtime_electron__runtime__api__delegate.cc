--- electron/shell/browser/extensions/api/runtime/electron_runtime_api_delegate.cc.orig	2026-06-29 20:35:15 UTC
+++ electron/shell/browser/extensions/api/runtime/electron_runtime_api_delegate.cc
@@ -56,6 +56,8 @@ bool ElectronRuntimeAPIDelegate::GetPlatformInfo(Platf
     info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (os == "openbsd") {
     info->os = extensions::api::runtime::PlatformOs::kOpenbsd;
+  } else if (os == "freebsd") {
+    info->os = extensions::api::runtime::PlatformOs::kFreebsd;
   } else {
     NOTREACHED();
   }
