# Description: Fix abort() on ARM related to __clear_cache(). This is an issue
# for anything !apple that is using the libcompiler_rt provided by clang on ARM
# PR: ports/149167 ports/184517
# Patch by: cognet@ (to be upstreamed @ LLVM)

--- src/arm/ffi.c.orig	2014-11-08 12:47:24 UTC
+++ src/arm/ffi.c
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
@@ -750,6 +755,16 @@ ffi_closure_free (void *ptr)
 }
 
 #else
+
+#if defined(__FreeBSD__) && defined(__arm__)
+#define __clear_cache(start, end) do { \
+		struct arm_sync_icache_args ua; 		\
+								\
+		ua.addr = (uintptr_t)(start);			\
+		ua.len = (char *)(end) - (char *)start;		\
+		sysarch(ARM_SYNC_ICACHE, &ua);			\
+	} while (0);
+#endif
 
 #define FFI_INIT_TRAMPOLINE(TRAMP,FUN,CTX)				\
 ({ unsigned char *__tramp = (unsigned char*)(TRAMP);			\
