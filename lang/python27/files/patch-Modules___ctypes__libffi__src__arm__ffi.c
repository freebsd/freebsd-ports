# Description: Fix _ctypes abort on import for FreeBSD/ARM. This is an issue
# for anything !apple that is using the libcompiler_rt provided by clang on arm
# PR: ports/149167 ports/184517
# Patch by: cognet@ (to be upstreamed @ LLVM)

--- ./Modules/_ctypes/libffi/src/arm/ffi.c.orig	2013-11-10 18:36:41.000000000 +1100	
+++ ./Modules/_ctypes/libffi/src/arm/ffi.c	2013-12-03 18:05:51.461078888 +1100
@@ -33,6 +33,11 @@
 
 #include <stdlib.h>
 
+#if defined(__FreeBSD__) && defined(__arm__)
+#include <sys/types.h>
+#include <machine/sysarch.h>
+#endif
+
 /* Forward declares. */
 static int vfp_type_p (ffi_type *);
 static void layout_vfp_args (ffi_cif *);
@@ -751,6 +756,16 @@ ffi_closure_free (void *ptr)
 
 #else
 
+#if defined(__FreeBSD__) && defined(__arm__)
+#define __clear_cache(start, end) do { \
+		struct arm_sync_icache_args ua; 		\
+								\
+		ua.addr = (uintptr_t)(start);			\
+		ua.len = (char *)(end) - (char *)start;		\
+		sysarch(ARM_SYNC_ICACHE, &ua);			\
+	} while (0);
+#endif
+
 #define FFI_INIT_TRAMPOLINE(TRAMP,FUN,CTX)				\
 ({ unsigned char *__tramp = (unsigned char*)(TRAMP);			\
    unsigned int  __fun = (unsigned int)(FUN);				\
