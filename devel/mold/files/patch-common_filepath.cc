--- common/filepath.cc.orig	2024-05-03 15:37:12 UTC
+++ common/filepath.cc
@@ -3,6 +3,10 @@
 #include <filesystem>
 #include <sys/stat.h>
 
+#ifdef __FreeBSD__
+# include <sys/sysctl.h>
+#endif
+
 #ifdef __APPLE__
 # include <mach-o/dyld.h>
 #endif
