--- third_party/vulkan-deps/vulkan-loader/src/loader/stack_allocation.h.orig	2022-09-01 05:13:41 UTC
+++ third_party/vulkan-deps/vulkan-loader/src/loader/stack_allocation.h
@@ -30,11 +30,11 @@
 
 #if defined(_WIN32)
 #include <malloc.h>
-#else
+#elif !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <alloca.h>
 #endif
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 #define loader_stack_alloc(size) alloca(size)
 #elif defined(_WIN32)
 #define loader_stack_alloc(size) _alloca(size)
