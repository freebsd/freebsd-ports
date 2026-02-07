--- lib/smutils.hh.orig	2021-06-27 09:10:34 UTC
+++ lib/smutils.hh
@@ -13,6 +13,8 @@
   #define SM_OS_MACOS
 #elif __linux__
   #define SM_OS_LINUX
+#elif __FreeBSD__
+  #define SM_OS_LINUX
 #else
   #error "unsupported platform"
 #endif
