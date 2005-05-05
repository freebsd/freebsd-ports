--- common/gr_memory.h.orig	Wed May  4 18:49:43 2005
+++ common/gr_memory.h	Wed May  4 18:49:45 2005
@@ -64,7 +64,7 @@
 void	gr_dlist_free			(GrDList *list);
 
 #define gr_FOREACH(l,p) \
-  for (; (l) != NULL && ((void *)(p) = (l)->data, 1); (l) = (l)->next) 
+  for (; (l) != NULL && ((p) = (l)->data, 1); (l) = (l)->next) 
 
 void	gr_ref_incr			(GrRef *ref);
 void	gr_ref_decr			(GrRef *ref);
