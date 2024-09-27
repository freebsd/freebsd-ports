--- include/list.h.orig	2014-01-20 22:47:46 UTC
+++ include/list.h
@@ -29,7 +29,7 @@ struct list_head {
 
 #define LIST_HEAD_INIT(name) { &(name), &(name) }
 
-#define LIST_HEAD(name) \
+#define XFS_LIST_HEAD(name) \
 		struct list_head name = LIST_HEAD_INIT(name)
 
 #define INIT_LIST_HEAD(list) list_head_init(list)
