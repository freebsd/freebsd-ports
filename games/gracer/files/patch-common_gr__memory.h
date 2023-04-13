--- common/gr_memory.h.orig	2000-03-01 04:27:04 UTC
+++ common/gr_memory.h
@@ -29,7 +29,7 @@ extern "C" {
 }
 #endif
 
-#include <malloc.h>
+#include <stdlib.h>
 
 #define gr_new(type,num)	(type *) malloc (sizeof(type) * (num))
 #define gr_new0(type,num)	(type *) __malloc0 (sizeof(type) * (num))
@@ -64,7 +64,7 @@ void	gr_slist_free			(GrSList *list);
 void	gr_dlist_free			(GrDList *list);
 
 #define gr_FOREACH(l,p) \
-  for (; (l) != NULL && ((void *)(p) = (l)->data, 1); (l) = (l)->next) 
+  for (; (l) != NULL && ((p) = (l)->data, 1); (l) = (l)->next) 
 
 void	gr_ref_incr			(GrRef *ref);
 void	gr_ref_decr			(GrRef *ref);
