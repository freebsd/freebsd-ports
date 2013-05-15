--- src/tclhash.c.orig	2013-05-13 15:18:05.000000000 +0200
+++ src/tclhash.c	2013-05-13 15:18:12.000000000 +0200
@@ -113,7 +113,7 @@
   nfree(tl);
 }
 
-inline void garbage_collect_tclhash(void)
+void garbage_collect_tclhash(void)
 {
   tcl_bind_list_t *tl, *tl_next, *tl_prev;
   tcl_bind_mask_t *tm, *tm_next, *tm_prev;
