- Unbreak build with GCC:

../util/exe_path.cc: In function 'base::FilePath GetExePath()':
../util/exe_path.cc:56:12: error: 'PATH_MAX' was not declared in this scope
   56 |   char buf[PATH_MAX];
      |            ^~~~~~~~
../util/exe_path.cc:58:22: error: 'buf' was not declared in this scope
   58 |   if (sysctl(mib, 4, buf, &buf_size, nullptr, 0) == -1) {
      |                      ^~~
../util/exe_path.cc:61:25: error: 'buf' was not declared in this scope
   61 |   return base::FilePath(buf);
      |                         ^~~

--- util/exe_path.cc.orig	2019-05-30 00:15:11 UTC
+++ util/exe_path.cc
@@ -16,6 +16,7 @@
 #elif defined(OS_FREEBSD)
 #include <sys/sysctl.h>
 #include <sys/types.h>
+#include <limits.h> // PATH_MAX
 #endif
 
 #if defined(OS_MACOSX)
