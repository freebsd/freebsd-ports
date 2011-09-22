--- src/runtime/gencgc-internal.h.orig	2011-09-21 17:45:32.000000000 -0700
+++ src/runtime/gencgc-internal.h	2011-09-21 17:46:00.000000000 -0700
@@ -25,8 +25,8 @@
 #include "genesis/code.h"
 
 void gc_free_heap(void);
-inline page_index_t find_page_index(void *);
-inline void *page_address(page_index_t);
+extern page_index_t find_page_index(void *);
+extern void *page_address(page_index_t);
 int gencgc_handle_wp_violation(void *);
 
 
