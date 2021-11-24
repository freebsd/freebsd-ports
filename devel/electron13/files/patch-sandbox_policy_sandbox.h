--- sandbox/policy/sandbox.h.orig	2021-07-15 19:13:43 UTC
+++ sandbox/policy/sandbox.h
@@ -9,6 +9,10 @@
 #include "sandbox/policy/export.h"
 #include "sandbox/policy/sandbox_type.h"
 
+#if defined(OS_FREEBSD)
+#include "sandbox/policy/freebsd/sandbox_freebsd.h"
+#endif
+
 #if defined(OS_LINUX) || defined(OS_CHROMEOS)
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif
@@ -30,6 +34,10 @@ namespace policy {
 
 class SANDBOX_POLICY_EXPORT Sandbox {
  public:
+#if defined(OS_FREEBSD)
+  static bool Initialize(SandboxType sandbox_type);
+#endif  // defined(OS_FREEBSD)
+
 #if defined(OS_LINUX) || defined(OS_CHROMEOS)
   static bool Initialize(SandboxType sandbox_type,
                          SandboxLinux::PreSandboxHook hook,
