--- external/glpk/glpspx02.c.orig	2026-06-09 15:25:39 UTC
+++ external/glpk/glpspx02.c
@@ -89,7 +89,7 @@ struct csa
       /* non-zero element values */
 #if 1 /* 06/IV-2009 */
       /* constraint matrix A stored by rows */
-      int *AT_ptr; /* int AT_ptr[1+m+1];
+      int *AT_ptr; /* int AT_ptr[1+m+1]; */
       /* AT_ptr[0] is not used;
          AT_ptr[i], 1 <= i <= m, is starting position of i-th row in
          arrays AT_ind and AT_val; note that AT_ptr[1] is always 1;
