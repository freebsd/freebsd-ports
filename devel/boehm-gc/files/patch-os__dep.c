--- os_dep.c.orig	2014-06-03 06:08:02 UTC
+++ os_dep.c
@@ -1869,7 +1869,8 @@ void GC_register_data_segments(void)
 # endif
 
 # if defined(FREEBSD) && !defined(PCR) && (defined(I386) || defined(X86_64) \
-                                || defined(powerpc) || defined(__powerpc__))
+                                || defined(powerpc) || defined(__powerpc__) \
+				|| defined(__aarch64__))
 
 /* Its unclear whether this should be identical to the above, or        */
 /* whether it should apply to non-X86 architectures.                    */
@@ -3094,6 +3095,8 @@ GC_API GC_push_other_roots_proc GC_CALL 
 #       include <machine/trap.h>
 #       define CODE_OK (si -> si_code == EXC_DSI \
                         || si -> si_code == SEGV_ACCERR)
+#     elif defined(AARCH64)
+#       define CODE_OK (si -> si_code == SEGV_ACCERR)
 #     else
 #       define CODE_OK (si -> si_code == BUS_PAGE_FAULT \
                         || si -> si_code == SEGV_ACCERR)
