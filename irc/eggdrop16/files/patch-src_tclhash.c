$NetBSD: patch-src_tclhash.c,v 1.1 2012/11/16 00:35:28 joerg Exp $

--- src/tclhash.c.orig	2012-11-15 10:32:40.000000000 +0000
+++ src/tclhash.c
@@ -109,7 +109,7 @@ static inline void tcl_bind_list_delete(
   nfree(tl);
 }
 
-inline void garbage_collect_tclhash(void)
+void garbage_collect_tclhash(void)
 {
   tcl_bind_list_t *tl, *tl_next, *tl_prev;
   tcl_bind_mask_t *tm, *tm_next, *tm_prev;
