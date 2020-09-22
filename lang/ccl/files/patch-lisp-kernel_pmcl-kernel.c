--- lisp-kernel/pmcl-kernel.c.orig	2020-04-19 21:32:56 UTC
+++ lisp-kernel/pmcl-kernel.c
@@ -151,7 +151,7 @@ wperror(char* message)
 
 LispObj lisp_nil = (LispObj) 0;
 bitvector global_mark_ref_bits = NULL, dynamic_mark_ref_bits = NULL, relocatable_mark_ref_bits = NULL, global_refidx = NULL, dynamic_refidx = NULL,managed_static_refidx = NULL;
-
+void *tcr_area_lock;
 
 /* These are all "persistent" : they're initialized when
    subprims are first loaded and should never change. */
