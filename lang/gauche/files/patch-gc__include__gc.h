--- ./gc/include/gc.h.orig	Sat Mar  4 12:55:44 2006
+++ ./gc/include/gc.h	Tue May  9 14:38:56 2006
@@ -504,6 +504,7 @@
     /* gcc knows how to retrieve return address, but we don't know */
     /* how to generate call stacks.				   */
 #   define GC_RETURN_ADDR (GC_word)__builtin_return_address(0)
+#   define GC_RETURN_ADDR_PARENT (GC_word)__builtin_return_address(1)
 # else
     /* Just pass 0 for gcc compatibility. */
 #   define GC_RETURN_ADDR 0
