--- src/ct_main.c.orig	Thu Jun  3 05:04:08 2004
+++ src/ct_main.c	Thu Jun  3 05:05:51 2004
@@ -5758,7 +5758,7 @@
    /* Install own SIGILL handler */
    sigill_new.ksa_handler  = cpuid_SIGILL_handler;
    sigill_new.ksa_flags    = 0;
-   sigill_new.ksa_restorer = NULL;
+   //   sigill_new.ksa_restorer = NULL;
    res = VG_(ksigemptyset)( &sigill_new.ksa_mask );
    CT_ASSERT(res == 0);
 
