--- include/gc.h.orig	Wed Jun  4 17:07:33 2003
+++ include/gc.h	Wed May 12 20:03:22 2004
@@ -487,6 +487,7 @@
     /* gcc knows how to retrieve return address, but we don't know */
     /* how to generate call stacks.				   */
 #   define GC_RETURN_ADDR (GC_word)__builtin_return_address(0)
+#   define GC_RETURN_ADDR_PARENT (GC_word)__builtin_return_address(1)
 # else
     /* Just pass 0 for gcc compatibility. */
 #   define GC_RETURN_ADDR 0
