In file included from loader/asm_offset.c:26:
In file included from loader/loader.h:32:
In file included from loader/loader_common.h:32:
In file included from loader/vk_loader_platform.h:79:
loader/stack_allocation.h:34:10: fatal error: 'alloca.h' file not found
#include <alloca.h>
         ^~~~~~~~~~

--- loader/stack_allocation.h.orig	2022-06-30 18:28:09 UTC
+++ loader/stack_allocation.h
@@ -30,8 +30,6 @@
 
 #if defined(_WIN32)
 #include <malloc.h>
-#else
-#include <alloca.h>
 #endif
 
 #if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__)
