--- sim/igen/gen-engine.c.orig	Fri Feb 20 19:21:21 2004
+++ sim/igen/gen-engine.c	Fri Feb 20 19:22:13 2004
@@ -98,21 +98,21 @@
   if (!options.gen.smp)
     {
       
-      lf_putstr (file, "
-/* CASE 1: NO SMP (with or with out instruction cache).
-
-In this case, we can take advantage of the fact that the current
-instruction address (CIA) does not need to be read from / written to
-the CPU object after the execution of an instruction.
-
-Instead, CIA is only saved when the main loop exits.  This occures
-when either sim_engine_halt or sim_engine_restart is called.  Both of
-these functions save the current instruction address before halting /
-restarting the simulator.
-
-As a variation, there may also be support for an instruction cracking
-cache. */
-
+      lf_putstr (file, "\
+/* CASE 1: NO SMP (with or with out instruction cache).\
+\
+In this case, we can take advantage of the fact that the current\
+instruction address (CIA) does not need to be read from / written to\
+the CPU object after the execution of an instruction.\
+\
+Instead, CIA is only saved when the main loop exits.  This occures\
+when either sim_engine_halt or sim_engine_restart is called.  Both of\
+these functions save the current instruction address before halting /\
+restarting the simulator.\
+\
+As a variation, there may also be support for an instruction cracking\
+cache. */\
+\
 ");
 
       lf_putstr (file, "\n");
@@ -215,14 +215,14 @@
   if (options.gen.smp)
     {
       
-      lf_putstr (file, "
-/* CASE 2: SMP (With or without ICACHE)
-
-The complexity here comes from needing to correctly halt the simulator
-when it is aborted.  For instance, if cpu0 requests a restart then
-cpu1 will normally be the next cpu that is run.  Cpu0 being restarted
-after all the other CPU's and the event queue have been processed */
-
+      lf_putstr (file, "\
+/* CASE 2: SMP (With or without ICACHE)\
+\
+The complexity here comes from needing to correctly halt the simulator\
+when it is aborted.  For instance, if cpu0 requests a restart then\
+cpu1 will normally be the next cpu that is run.  Cpu0 being restarted\
+after all the other CPU's and the event queue have been processed */\
+\
 ");
       
       lf_putstr (file, "\n");
