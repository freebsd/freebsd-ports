--- sim/ppc/gen-idecode.c.orig	Fri Feb 20 17:00:10 2004
+++ sim/ppc/gen-idecode.c	Fri Feb 20 17:00:57 2004
@@ -757,21 +757,21 @@
 
   if (!generate_smp) {
 
-    lf_putstr(file, "
-/* CASE 1: NO SMP (with or with out instruction cache).
-
-   In this case, we can take advantage of the fact that the current
-   instruction address does not need to be returned to the cpu object
-   after every execution of an instruction.  Instead it only needs to
-   be saved when either A. the main loop exits or B. A cpu-halt or
-   cpu-restart call forces the loop to be re-enered.  The later
-   functions always save the current cpu instruction address.
-
-   Two subcases also exist that with and that without an instruction
-   cache.
-
-   An additional complexity is the need to ensure that a 1:1 ratio
-   is maintained between the execution of an instruction and the
+    lf_putstr(file, "\
+/* CASE 1: NO SMP (with or with out instruction cache).\
+\
+   In this case, we can take advantage of the fact that the current\
+   instruction address does not need to be returned to the cpu object\
+   after every execution of an instruction.  Instead it only needs to\
+   be saved when either A. the main loop exits or B. A cpu-halt or\
+   cpu-restart call forces the loop to be re-enered.  The later\
+   functions always save the current cpu instruction address.\
+\
+   Two subcases also exist that with and that without an instruction\
+   cache.\
+\
+   An additional complexity is the need to ensure that a 1:1 ratio\
+   is maintained between the execution of an instruction and the\
    incrementing of the simulation clock */");
 
     lf_putstr(file, "\n");
@@ -867,12 +867,12 @@
     
   if (generate_smp) {
 
-    lf_putstr(file, "
-/* CASE 2: SMP (With or without ICACHE)
-
-   The complexity here comes from needing to correctly restart the
-   system when it is aborted.  In particular if cpu0 requests a
-   restart, the next cpu is still cpu1.  Cpu0 being restarted after
+    lf_putstr(file, "\
+/* CASE 2: SMP (With or without ICACHE)\
+\
+   The complexity here comes from needing to correctly restart the\
+   system when it is aborted.  In particular if cpu0 requests a\
+   restart, the next cpu is still cpu1.  Cpu0 being restarted after\
    all the other CPU's and the event queue have been processed */");
 
     lf_putstr(file, "\n");
