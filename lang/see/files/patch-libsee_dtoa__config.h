--- libsee/dtoa_config.h.orig	2022-11-12 15:54:29 UTC
+++ libsee/dtoa_config.h
@@ -11,7 +11,8 @@
 
 #include <see/type.h>
 
-#if defined(__i386__) || defined(__amd64__) || defined(__ia64__) || defined(__alpha__)
+#if defined(__i386__) || defined(__amd64__) || defined(__ia64__) || defined(__alpha__) \
+    || defined(__arm__) || defined(__aarch64__) || defined(__riscv)
 #   define IEEE_8087
 #endif
 
