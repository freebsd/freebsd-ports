--- electron/atom/app/atom_main.cc.orig	2019-09-11 17:30:11 UTC
+++ electron/atom/app/atom_main.cc
@@ -26,12 +26,12 @@
 #include "base/win/windows_version.h"
 #include "content/public/app/sandbox_helper_win.h"
 #include "sandbox/win/src/sandbox_types.h"
-#elif defined(OS_LINUX)  // defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_BSD)  // defined(OS_WIN)
 #include <unistd.h>
 #include <cstdio>
 #include "atom/app/atom_main_delegate.h"  // NOLINT
 #include "content/public/app/content_main.h"
-#else  // defined(OS_LINUX)
+#else  // defined(OS_LINUX) || defined(OS_BSD)
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
