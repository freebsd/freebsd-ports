Index: src/xgccache.c
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/src/xgccache.c,v
retrieving revision 1.13
diff -u -r1.13 xgccache.c
--- src/xgccache.c	2005/11/26 11:46:11	1.13
+++ src/xgccache.c	2006/02/16 20:18:18
@@ -233,7 +233,9 @@
       cache->head = cell->next;
       cache->head->prev = 0;
       if (cache->tail == cell) cache->tail = 0; /* only one */
+#if 0
       debug_out ("Cache full, freeing GC: %08lx\n  ", XE_GCONTEXT(cell));
+#endif
       XFreeGC (cache->dpy, cell->gc);
       cache->delete_count++;
 #ifdef GCCACHE_HASH
