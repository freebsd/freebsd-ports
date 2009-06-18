--- gc.c.orig	2009-06-18 14:18:33.000000000 +0400
+++ gc.c	2009-06-18 14:18:45.000000000 +0400
@@ -1980,7 +1980,7 @@
 chain_finalized_object(st_data_t key, st_data_t val, st_data_t arg)
 {
     RVALUE *p = (RVALUE *)key, **final_list = (RVALUE **)arg;
-    if ((p->as.basic.flags & (FL_FINALIZE|FL_MARK)) == FL_FINALIZE) {
+    if ((p->as.basic.flags & (FL_FINALIZE)) == FL_FINALIZE) {
 	if (BUILTIN_TYPE(p) != T_DEFERRED) {
 	    p->as.free.flags = FL_MARK | T_DEFERRED; /* remain marked */
 	    RDATA(p)->dfree = 0;
