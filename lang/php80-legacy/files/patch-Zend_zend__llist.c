--- Zend/zend_llist.c.orig	2026-10-21 15:33:56 UTC
+++ Zend/zend_llist.c
@@ -112,6 +112,8 @@ ZEND_API void zend_llist_destroy(zend_llist *l)
 		current = next;
 	}
 
+	l->head  = NULL;
+	l->tail  = NULL;
 	l->count = 0;
 }
 
