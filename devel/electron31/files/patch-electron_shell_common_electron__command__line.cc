--- electron/shell/common/electron_command_line.cc.orig	2022-05-18 15:31:32 UTC
+++ electron/shell/common/electron_command_line.cc
@@ -26,7 +26,7 @@ void ElectronCommandLine::Init(int argc, base::Command
   argv_.assign(argv, argv + argc);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 void ElectronCommandLine::InitializeFromCommandLine() {
   argv_ = base::CommandLine::ForCurrentProcess()->argv();
