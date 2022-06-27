--- core/rec-x86/rec_x86_driver.cpp.orig	2022-05-20 09:34:27 UTC
+++ core/rec-x86/rec_x86_driver.cpp
@@ -31,7 +31,7 @@ RuntimeBlockInfo* ngen_AllocateBlock(void)
 
 x86_block* x86e;
 
-static int cycle_counter;
+int cycle_counter;
 
 void* loop_no_update;
 void* intc_sched;
