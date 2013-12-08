# Description: Fix _ctypes abort on import for FreeBSD/ARM. This is an issue
# for anything !apple that is using the libcompiler_rt provided by clang on arm
# PR: ports/149167 ports/184517
# Patch by: cognet@ (to be upstreamed @ LLVM)

--- ./Modules/_ctypes/libffi/src/arm/ffi.c.orig	2013-12-08 15:55:58.351993767 +1100
+++ ./Modules/_ctypes/libffi/src/arm/ffi.c	2013-12-08 15:57:40.531068291 +1100
@@ -29,6 +29,11 @@
 
 #include <stdlib.h>
 
+#if defined(__FreeBSD__) && defined(__arm__)
+#include <sys/types.h>
+#include <machine/sysarch.h>
+#endif
+
 /* ffi_prep_args is called by the assembly routine once stack space
    has been allocated for the function's arguments */
 
@@ -273,6 +278,16 @@
 
 /* How to make a trampoline.  */
 
+#if defined(__FreeBSD__) && defined(__arm__)
+#define __clear_cache(start, end) do { \
+                struct arm_sync_icache_args ua;                 \
+                                                                \
+                ua.addr = (uintptr_t)(start);                   \
+                ua.len = (char *)(end) - (char *)start;         \
+                sysarch(ARM_SYNC_ICACHE, &ua);                  \
+        } while (0);
+#endif
+
 #define FFI_INIT_TRAMPOLINE(TRAMP,FUN,CTX)				\
 ({ unsigned char *__tramp = (unsigned char*)(TRAMP);			\
    unsigned int  __fun = (unsigned int)(FUN);				\
