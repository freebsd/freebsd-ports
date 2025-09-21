--- passes/cmds/bugpoint.cc.orig	2025-09-21 18:06:28 UTC
+++ passes/cmds/bugpoint.cc
@@ -22,13 +22,14 @@
 
 #if defined(_WIN32)
 #  include <csignal>
+#endif
+
 #  define WIFEXITED(x) 1
 #  define WIFSIGNALED(x) 0
 #  define WIFSTOPPED(x) 0
 #  define WEXITSTATUS(x) ((x) & 0xff)
 #  define WTERMSIG(x) SIGTERM
 #  define WSTOPSIG(x) 0
-#endif
 
 USING_YOSYS_NAMESPACE
 using namespace RTLIL_BACKEND;
