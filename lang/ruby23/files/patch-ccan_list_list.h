--- ccan/list/list.h.orig	2015-09-06 07:10:54 UTC
+++ ccan/list/list.h
@@ -57,7 +57,7 @@ struct list_head
  * Example:
  *	static struct list_head my_list = LIST_HEAD_INIT(my_list);
  */
-#define LIST_HEAD_INIT(name) { { &name.n, &name.n } }
+#define CCAN_LIST_HEAD_INIT(name) { { &name.n, &name.n } }
 
 /**
  * LIST_HEAD - define and initialize an empty list_head
@@ -72,8 +72,8 @@ struct list_head
  * Example:
  *	static LIST_HEAD(my_global_list);
  */
-#define LIST_HEAD(name) \
-	struct list_head name = LIST_HEAD_INIT(name)
+#define CCAN_LIST_HEAD(name) \
+	struct list_head name = CCAN_LIST_HEAD_INIT(name)
 
 /**
  * list_head_init - initialize a list_head
