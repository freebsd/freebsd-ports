--- content/shell/app/shell_main_delegate.cc.orig	2019-09-10 11:14:03 UTC
+++ content/shell/app/shell_main_delegate.cc
@@ -170,7 +170,7 @@ bool ShellMainDelegate::BasicStartupComplete(int* exit
 
   v8_crashpad_support::SetUp();
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   breakpad::SetFirstChanceExceptionHandler(v8::TryHandleWebAssemblyTrapPosix);
 #endif
 #if defined(OS_MACOSX)
@@ -314,7 +314,7 @@ bool ShellMainDelegate::BasicStartupComplete(int* exit
 }
 
 void ShellMainDelegate::PreSandboxStartup() {
-#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX))
+#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD))
   // Create an instance of the CPU class to parse /proc/cpuinfo and cache
   // cpu_brand info.
   base::CPU cpu_info;
