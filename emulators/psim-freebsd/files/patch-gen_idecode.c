--- sim/ppc/gen-idecode.c	2003/10/20 23:10:45	1.1
+++ sim/ppc/gen-idecode.c	2003/10/20 23:16:21
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
+    lf_putstr(file, "\n\
+/* CASE 1: NO SMP (with or with out instruction cache).\n\
+\n\
+   In this case, we can take advantage of the fact that the current\n\
+   instruction address does not need to be returned to the cpu object\n\
+   after every execution of an instruction.  Instead it only needs to\n\
+   be saved when either A. the main loop exits or B. A cpu-halt or\n\
+   cpu-restart call forces the loop to be re-enered.  The later\n\
+   functions always save the current cpu instruction address.\n\
+\n\
+   Two subcases also exist that with and that without an instruction\n\
+   cache.\n\
+\n\
+   An additional complexity is the need to ensure that a 1:1 ratio\n\
+   is maintained between the execution of an instruction and the\n\
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
+    lf_putstr(file, "\n\
+/* CASE 2: SMP (With or without ICACHE)\n\
+\n\
+   The complexity here comes from needing to correctly restart the\n\
+   system when it is aborted.  In particular if cpu0 requests a\n\
+   restart, the next cpu is still cpu1.  Cpu0 being restarted after\n\
    all the other CPU's and the event queue have been processed */");
 
     lf_putstr(file, "\n");
