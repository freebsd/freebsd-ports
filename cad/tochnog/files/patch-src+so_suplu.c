--- so_suplu.c.orig	Thu May  6 03:24:22 2004
+++ so_suplu.c	Thu May  6 03:24:25 2004
@@ -53,6 +53,8 @@
   int *perm_r, *perm_c;
   int perm_spec;
   int nrhs;
+  SuperLUStat_t stat;
+  superlu_options_t options;
 #endif
 
   /* Create Matrix A in the format expected by SuperLU */
@@ -103,7 +105,9 @@
 
   /* Solve */
 #if SUPERLU_USE 
-  dgssv( &A, perm_c, perm_r, &L, &U, &B, &info );
+  /* Initialize the statistics variables. */
+  StatInit(&stat);
+  dgssv(&options, &A, perm_c, perm_r, &L, &U, &B, &stat, &info );
 #elif SUPERLU_MT_USE
   pdgssv( nthread, &A, perm_c, perm_r, &L, &U, &B, &info );
 #elif SUPERLU_DIST_USE
