--- so_suplu.c.orig	Fri Nov 10 05:59:39 2000
+++ so_suplu.c	Sun Mar 20 00:45:14 2005
@@ -53,6 +53,10 @@
   int *perm_r, *perm_c;
   int perm_spec;
   int nrhs;
+#if SUPERLU_USE
+  SuperLUStat_t stat;
+  superlu_options_t options;
+#endif
 #endif
 
   /* Create Matrix A in the format expected by SuperLU */
@@ -103,7 +107,9 @@
 
   /* Solve */
 #if SUPERLU_USE 
-  dgssv( &A, perm_c, perm_r, &L, &U, &B, &info );
+  /* Initialize the statistics variables. */
+  StatInit(&stat);
+  dgssv(&options, &A, perm_c, perm_r, &L, &U, &B, &stat, &info );
 #elif SUPERLU_MT_USE
   pdgssv( nthread, &A, perm_c, perm_r, &L, &U, &B, &info );
 #elif SUPERLU_DIST_USE
