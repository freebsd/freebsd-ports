--- electron/shell/common/electron_command_line.cc.orig	2020-05-18 21:17:08 UTC
+++ electron/shell/common/electron_command_line.cc
@@ -26,7 +26,7 @@ void ElectronCommandLine::Init(int argc, base::Command
   argv_.assign(argv, argv + argc);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 void ElectronCommandLine::InitializeFromCommandLine() {
   argv_ = base::CommandLine::ForCurrentProcess()->argv();
