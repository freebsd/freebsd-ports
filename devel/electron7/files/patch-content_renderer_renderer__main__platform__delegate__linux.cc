--- content/renderer/renderer_main_platform_delegate_linux.cc.orig	2019-12-12 12:39:41 UTC
+++ content/renderer/renderer_main_platform_delegate_linux.cc
@@ -30,6 +30,7 @@ void RendererMainPlatformDelegate::PlatformUninitializ
 }
 
 bool RendererMainPlatformDelegate::EnableSandbox() {
+#if !defined(OS_BSD)
   // The setuid sandbox is started in the zygote process: zygote_main_linux.cc
   // https://chromium.googlesource.com/chromium/src/+/master/docs/linux_suid_sandbox.md
   //
@@ -65,7 +66,7 @@ bool RendererMainPlatformDelegate::EnableSandbox() {
     CHECK_EQ(errno, EPERM);
   }
 #endif  // __x86_64__
-
+#endif  // ! OS_BSD
   return true;
 }
 
