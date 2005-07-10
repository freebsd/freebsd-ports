--- libgc/pthread_support.c.orig	Tue Jun 21 12:52:42 2005
+++ libgc/pthread_support.c	Tue Jun 21 12:54:17 2005
@@ -556,27 +556,6 @@
 
 volatile GC_thread GC_threads[THREAD_TABLE_SZ];
 
-/* 
- * gcc-3.3.6 miscompiles the &GC_thread_key+sizeof(&GC_thread_key) expression so
- * put it into a separate function.
- */
-#   ifdef __GNUC__
-static __attribute__((noinline)) unsigned char* get_gc_thread_key_addr GC_PROTO((void))
-{
-	return (unsigned char*)&GC_thread_key;
-}
-
-void GC_push_thread_structures GC_PROTO((void))
-{
-    GC_push_all((ptr_t)(GC_threads), (ptr_t)(GC_threads)+sizeof(GC_threads));
-#   if defined(THREAD_LOCAL_ALLOC) && !defined(DBG_HDRS_ALL)
-      GC_push_all((ptr_t)get_gc_thread_key_addr(),
-	  (ptr_t)(get_gc_thread_key_addr())+sizeof(&GC_thread_key));
-#   endif
-}
-
-#else
-
 void GC_push_thread_structures GC_PROTO((void))
 {
     GC_push_all((ptr_t)(GC_threads), (ptr_t)(GC_threads)+sizeof(GC_threads));
@@ -585,8 +564,6 @@
 	  (ptr_t)(&GC_thread_key)+sizeof(&GC_thread_key));
 #   endif
 }
-
-#endif
 
 #ifdef THREAD_LOCAL_ALLOC
 /* We must explicitly mark ptrfree and gcj free lists, since the free 	*/
