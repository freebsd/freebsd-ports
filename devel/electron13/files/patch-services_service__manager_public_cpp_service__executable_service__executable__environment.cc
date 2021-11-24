--- services/service_manager/public/cpp/service_executable/service_executable_environment.cc.orig	2021-07-15 19:13:43 UTC
+++ services/service_manager/public/cpp/service_executable/service_executable_environment.cc
@@ -50,6 +50,13 @@ ServiceExecutableEnvironment::ServiceExecutableEnviron
                 sandbox::policy::switches::kServiceSandboxType)),
         sandbox::policy::SandboxLinux::PreSandboxHook(), sandbox_options);
   }
+#elif defined(OS_FREEBSD)
+  if (command_line.HasSwitch(sandbox::policy::switches::kServiceSandboxType)) {
+    sandbox::policy::Sandbox::Initialize(
+        sandbox::policy::UtilitySandboxTypeFromString(
+            command_line.GetSwitchValueASCII(
+                sandbox::policy::switches::kServiceSandboxType)));
+  }
 #endif
 
   mojo::core::Init();
