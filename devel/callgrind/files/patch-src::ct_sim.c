--- src/ct_sim.c.orig	Tue Aug 31 13:05:51 2004
+++ src/ct_sim.c	Tue Aug 31 13:06:00 2004
@@ -537,7 +537,7 @@
    /* Install own SIGILL handler */
    sigill_new.ksa_handler  = cpuid_SIGILL_handler;
    sigill_new.ksa_flags    = 0;
-   sigill_new.ksa_restorer = NULL;
+   //sigill_new.ksa_restorer = NULL;
    res = VG_(ksigemptyset)( &sigill_new.ksa_mask );
    CT_ASSERT(res == 0);
 
