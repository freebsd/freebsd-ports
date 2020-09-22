--- lisp-kernel/area.h.orig	2020-04-19 21:32:56 UTC
+++ lisp-kernel/area.h
@@ -108,7 +108,7 @@ Boolean grow_dynamic_area(natural);
 Boolean shrink_dynamic_area(natural);
 
 /* serialize add_area/remove_area, and also the tcr queue */
-void *tcr_area_lock;
+extern void *tcr_area_lock;
 
 #define reserved_area ((area *)(all_areas))
 #define active_dynamic_area ((area *)(reserved_area->succ))
