--- libgc/pthread_support.c.orig	Mon Sep 11 02:58:08 2006
+++ libgc/pthread_support.c	Mon Sep 11 02:59:51 2006
@@ -597,23 +597,6 @@
  * gcc-3.3.6 miscompiles the &GC_thread_key+sizeof(&GC_thread_key) expression so
  * put it into a separate function.
  */
-#   if defined(__GNUC__) && defined(THREAD_LOCAL_ALLOC) && !defined(DBG_HDRS_ALL)
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
@@ -622,9 +605,6 @@
 	  (ptr_t)(&GC_thread_key)+sizeof(&GC_thread_key));
 #   endif
 }
-
-#endif
-
 #ifdef THREAD_LOCAL_ALLOC
 /* We must explicitly mark ptrfree and gcj free lists, since the free 	*/
 /* list links wouldn't otherwise be found.  We also set them in the 	*/
