--- sandbox/policy/sandbox.cc.orig	2021-07-15 19:13:43 UTC
+++ sandbox/policy/sandbox.cc
@@ -12,6 +12,10 @@
 #include "base/android/jni_android.h"
 #endif  // defined(OS_ANDROID)
 
+#if defined(OS_FREEBSD)
+#include "sandbox/policy/freebsd/sandbox_freebsd.h"
+#endif  // defined(OS_FREEBSD)
+
 #if defined(OS_LINUX) || defined(OS_CHROMEOS)
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
@@ -29,6 +33,12 @@
 namespace sandbox {
 namespace policy {
 
+#if defined(OS_FREEBSD)
+bool Sandbox::Initialize(SandboxType sandbox_type) {
+  return SandboxFreeBSD::GetInstance()->InitializeSandbox(sandbox_type);
+}
+#endif  // defined(OS_FREEBSD)
+
 #if defined(OS_LINUX) || defined(OS_CHROMEOS)
 bool Sandbox::Initialize(SandboxType sandbox_type,
                          SandboxLinux::PreSandboxHook hook,
@@ -89,6 +99,8 @@ bool Sandbox::IsProcessSandboxed() {
       base::android::MethodID::Get<base::android::MethodID::TYPE_STATIC>(
           env, process_class.obj(), "isIsolated", "()Z");
   return env->CallStaticBooleanMethod(process_class.obj(), is_isolated);
+#elif defined(OS_FREEBSD)
+  return SandboxFreeBSD::GetInstance()->IsSandboxed();
 #elif defined(OS_FUCHSIA)
   // TODO(https://crbug.com/1071420): Figure out what to do here. Process
   // launching controls the sandbox and there are no ambient capabilities, so
