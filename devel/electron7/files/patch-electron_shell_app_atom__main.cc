--- electron/shell/app/atom_main.cc.orig	2019-12-13 19:48:14 UTC
+++ electron/shell/app/atom_main.cc
@@ -26,12 +26,12 @@
 #include "shell/app/atom_main_delegate.h"
 #include "shell/app/command_line_args.h"
 #include "shell/common/crash_reporter/win/crash_service_main.h"
-#elif defined(OS_LINUX)  // defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_BSD)  // defined(OS_WIN)
 #include <unistd.h>
 #include <cstdio>
 #include "content/public/app/content_main.h"
 #include "shell/app/atom_main_delegate.h"  // NOLINT
-#else                                      // defined(OS_LINUX)
+#else                                      // defined(OS_LINUX) || defined(OS_BSD)
 #include <mach-o/dyld.h>
 #include <unistd.h>
 #include <cstdio>
@@ -168,7 +168,7 @@ int APIENTRY wWinMain(HINSTANCE instance, HINSTANCE, w
   return content::ContentMain(params);
 }
 
-#elif defined(OS_LINUX)  // defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_BSD) // defined(OS_WIN)
 
 int main(int argc, char* argv[]) {
   FixStdioStreams();
@@ -189,7 +189,7 @@ int main(int argc, char* argv[]) {
   return content::ContentMain(params);
 }
 
-#else  // defined(OS_LINUX)
+#else  // defined(OS_LINUX) || defined(OS_BSD)
 
 int main(int argc, char* argv[]) {
   FixStdioStreams();
