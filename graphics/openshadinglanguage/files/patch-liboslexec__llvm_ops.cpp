--- ./liboslexec/llvm_ops.cpp.orig	2013-02-17 07:12:22.136610427 +1030
+++ ./liboslexec/llvm_ops.cpp	2013-02-17 07:13:26.175610292 +1030
@@ -127,8 +127,8 @@
 
 #if defined(__FreeBSD__)
 #include <sys/param.h>
-#if __FreeBSD_version < 803000
-// freebsd before 8.3 doesn't have log2f - use OIIO lib replacement
+#if __FreeBSD_version < 802502
+// freebsd before 8.2-STABLE doesn't have log2f - use OIIO lib replacement
 using OIIO::log2f;
 #endif
 #endif
