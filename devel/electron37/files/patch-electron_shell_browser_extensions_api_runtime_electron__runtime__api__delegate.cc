--- electron/shell/browser/extensions/api/runtime/electron_runtime_api_delegate.cc.orig	2025-07-02 10:12:01 UTC
+++ electron/shell/browser/extensions/api/runtime/electron_runtime_api_delegate.cc
@@ -55,6 +55,8 @@ bool ElectronRuntimeAPIDelegate::GetPlatformInfo(Platf
     info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (os == "openbsd") {
     info->os = extensions::api::runtime::PlatformOs::kOpenbsd;
+  } else if (os == "freebsd") {
+    info->os = extensions::api::runtime::PlatformOs::kFreebsd;
   } else {
     NOTREACHED();
   }
