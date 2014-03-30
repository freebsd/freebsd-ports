--- ./vierinit.c.orig	1992-07-29 02:04:24.000000000 +0200
+++ ./vierinit.c	2014-03-30 13:14:36.798575126 +0200
@@ -78,7 +78,7 @@
       pui++;
     }
   _p_h_ = (int *)malloc((row_col + 4 * vnum) * sizeof(int));
-  pp = (int **)malloc(row_col * sizeof(int));
+  pp = (int **)malloc(row_col * sizeof(int *));
   for (pui = i = 0; i < row_col; i++) {
     pp[i] = _p_h_ + pui;
     for (j = 0; j < vnum; j++)
