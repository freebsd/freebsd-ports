--- include/private/gc_priv.h.orig	2014-06-03 06:08:02 UTC
+++ include/private/gc_priv.h
@@ -2461,7 +2461,9 @@ GC_INNER ptr_t GC_store_debug_info(ptr_t
 #endif
 
 #if defined(FREEBSD) && (defined(I386) || defined(X86_64) \
-                        || defined(powerpc) || defined(__powerpc__))
+                        || defined(powerpc) || defined(__powerpc__) \
+			|| defined(__aarch64__))
+
 # include <machine/trap.h>
 # if !defined(PCR)
 #   define NEED_FIND_LIMIT
