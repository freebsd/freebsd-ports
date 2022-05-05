# Description: Fix abort() on ARM related to __clear_cache(). This is an issue
# for anything !apple that is using the libcompiler_rt provided by clang on ARM
# PR: ports/149167 ports/184517
# Patch by: cognet@ (to be upstreamed @ LLVM)

--- src/arm/ffi.c.orig	2019-10-31 14:49:54 UTC
+++ src/arm/ffi.c
@@ -55,6 +55,11 @@ extern unsigned int ffi_arm_trampoline[3] FFI_HIDDEN;
 #endif
 #endif
 
+#if defined(__FreeBSD__) && defined(__arm__)
+#include <sys/types.h>
+#include <machine/sysarch.h>
+#endif
+
 /* Forward declares. */
 static int vfp_type_p (const ffi_type *);
 static void layout_vfp_args (ffi_cif *);
@@ -568,6 +573,16 @@ void ffi_go_closure_SYSV (void) FFI_HIDDEN;
 void ffi_go_closure_VFP (void) FFI_HIDDEN;
 
 /* the cif must already be prep'ed */
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
 
 ffi_status
 ffi_prep_closure_loc (ffi_closure * closure,
