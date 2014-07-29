--- src/list.h.orig	Mon Nov 13 03:42:45 2000
+++ src/list.h	Thu Oct 16 22:36:07 2003
@@ -52,10 +52,10 @@
   ((NULL == (list)) || (NULL == ((header *)(list))->next))
 
 /* NewList creates a header for a list of the specified type */
-#define NewList(type) ( ##type## *)calloc(1, sizeof( ##type## ))
+#define NewList(type) (type *)calloc(1, sizeof(type))
 
 /* NewEntry allocates a new entry of the specified type */
-#define NewEntry(type) ( ##type## *)calloc(1, sizeof( ##type## ))
+#define NewEntry(type) (type *)calloc(1, sizeof(type))
 
 #define RemoveFirst(list) RemoveEntry((list), (list).h->next)
 #define RemoveLast(list)  RemoveEntry((list), (list).h->prev)
