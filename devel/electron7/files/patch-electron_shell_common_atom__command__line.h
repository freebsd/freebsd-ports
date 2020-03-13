--- electron/shell/common/atom_command_line.h.orig	2019-12-13 19:48:14 UTC
+++ electron/shell/common/atom_command_line.h
@@ -21,7 +21,7 @@ class AtomCommandLine {
 
   static void Init(int argc, base::CommandLine::CharType** argv);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux the command line has to be read from base::CommandLine since
   // it is using zygote.
   static void InitializeFromCommandLine();
