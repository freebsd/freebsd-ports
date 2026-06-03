--- application/F3DSystemTools.cxx.orig	2026-04-05 11:41:50 UTC
+++ application/F3DSystemTools.cxx
@@ -19,6 +19,10 @@
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #endif
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 
 namespace fs = std::filesystem;
 
