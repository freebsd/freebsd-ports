--- electron/shell/common/atom_command_line.cc.orig	2019-12-13 19:48:14 UTC
+++ electron/shell/common/atom_command_line.cc
@@ -26,7 +26,7 @@ void AtomCommandLine::Init(int argc, base::CommandLine
   argv_.assign(argv, argv + argc);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 void AtomCommandLine::InitializeFromCommandLine() {
   argv_ = base::CommandLine::ForCurrentProcess()->argv();
