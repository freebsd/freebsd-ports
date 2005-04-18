--- include/see/mem.h.orig	Mon Apr 18 13:01:27 2005
+++ include/see/mem.h	Mon Apr 18 13:01:45 2005
@@ -15,8 +15,8 @@
 #define SEE_NEW(i, t)		(t *)SEE_malloc(i, sizeof (t))
 #define SEE_NEW_ARRAY(i, t, n)	(t *)SEE_malloc(i, (n) * sizeof (t))
 
-void *(*SEE_mem_malloc_hook)(struct SEE_interpreter *i, unsigned int sz);
-void  (*SEE_mem_free_hook)(struct SEE_interpreter *i, void *ptr);
-void  (*SEE_mem_exhausted_hook)(struct SEE_interpreter *i) SEE_dead;
+extern void *(*SEE_mem_malloc_hook)(struct SEE_interpreter *i, unsigned int sz);
+extern void  (*SEE_mem_free_hook)(struct SEE_interpreter *i, void *ptr);
+extern void  (*SEE_mem_exhausted_hook)(struct SEE_interpreter *i) SEE_dead;
 
 #endif /* _SEE_h_mem_ */
