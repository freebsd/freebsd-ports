--- extlibs/gc-cvs/include/private/gc_priv.h.orig	2020-08-24 13:57:21 UTC
+++ extlibs/gc-cvs/include/private/gc_priv.h
@@ -2169,7 +2169,7 @@ GC_EXTERN signed_word GC_bytes_found;
 
 #if defined(NEED_FIND_LIMIT) \
      || (defined(USE_PROC_FOR_LIBRARIES) && defined(THREADS))
-  JMP_BUF GC_jmp_buf;
+  GC_EXTERN JMP_BUF GC_jmp_buf;
 
   /* Set up a handler for address faults which will longjmp to  */
   /* GC_jmp_buf;                                                */
