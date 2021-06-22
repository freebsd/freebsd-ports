--- tools/driver-tool/cmdline.cpp.orig	2021-04-21 19:42:12 UTC
+++ tools/driver-tool/cmdline.cpp
@@ -50,6 +50,10 @@
 #define environ (*_NSGetEnviron())
 #endif
 
+#if defined(__FreeBSD__)
+extern char **environ;
+#endif
+
 #define TRACE( lvl, ... ) /* ignore */
 
 namespace ncbi
