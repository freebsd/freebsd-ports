--- content/renderer/renderer_main_platform_delegate_linux.cc.orig	2021-07-15 19:13:39 UTC
+++ content/renderer/renderer_main_platform_delegate_linux.cc
@@ -30,6 +30,11 @@ void RendererMainPlatformDelegate::PlatformUninitializ
 }
 
 bool RendererMainPlatformDelegate::EnableSandbox() {
+#if defined(OS_FREEBSD)
+  sandbox::policy::Sandbox::Initialize(
+      sandbox::policy::SandboxTypeFromCommandLine(
+          *base::CommandLine::ForCurrentProcess()));
+#else
   // The setuid sandbox is started in the zygote process: zygote_main_linux.cc
   // https://chromium.googlesource.com/chromium/src/+/master/docs/linux/suid_sandbox.md
   //
@@ -65,7 +70,7 @@ bool RendererMainPlatformDelegate::EnableSandbox() {
     CHECK_EQ(errno, EPERM);
   }
 #endif  // __x86_64__
-
+#endif  // OS_FREEBSD
   return true;
 }
 
