--- viterbi615_av.c.orig	2019-02-05 19:33:18 UTC
+++ viterbi615_av.c
@@ -3,6 +3,7 @@
  * Copyright Mar 2004, Phil Karn, KA9Q
  * May be used under the terms of the GNU Lesser General Public License (LGPL)
  */
+#include <altivec.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <memory.h>
@@ -33,7 +34,7 @@ int init_viterbi615_av(void *p,int starting_state){
     return -1;
 
   for(i=0;i<2048;i++)
-    vp->metrics1.v[i] = (vector unsigned short)(5000);
+    vp->metrics1.v[i] = (vector unsigned short){5000};
 
   vp->old_metrics = &vp->metrics1;
   vp->new_metrics = &vp->metrics2;
@@ -111,7 +112,7 @@ int update_viterbi615_blk_av(void *p,unsigned char *sy
   struct v615 *vp = p;
   decision_t *d = (decision_t *)vp->dp;
   int path_metric = 0;
-  vector unsigned char decisions = (vector unsigned char)(0);
+  vector unsigned char decisions = (vector unsigned char){0};
 
   while(nbits--){
     vector unsigned short symv,sym0v,sym1v,sym2v,sym3v,sym4v,sym5v;
@@ -122,7 +123,7 @@ int update_viterbi615_blk_av(void *p,unsigned char *sy
     /* Splat the 0th symbol across sym0v, the 1st symbol across sym1v, etc */
     s = (vector unsigned char)vec_perm(vec_ld(0,syms),vec_ld(5,syms),vec_lvsl(0,syms));
 
-    symv = (vector unsigned short)vec_mergeh((vector unsigned char)(0),s);    /* Unsigned byte->word unpack */ 
+    symv = (vector unsigned short)vec_mergeh((vector unsigned char){0},s);    /* Unsigned byte->word unpack */ 
     sym0v = vec_splat(symv,0);
     sym1v = vec_splat(symv,1);
     sym2v = vec_splat(symv,2);
@@ -145,7 +146,7 @@ int update_viterbi615_blk_av(void *p,unsigned char *sy
       m2 = vec_add(vec_xor(Branchtab615[4].v[i],sym4v),vec_xor(Branchtab615[5].v[i],sym5v));
       metric = vec_add(m0,m1);
       metric = vec_add(metric,m2);
-      m_metric = vec_sub((vector unsigned short)(1530),metric);
+      m_metric = vec_sub((vector unsigned short){1530},metric);
     
       /* Add branch metrics to path metrics */
       m0 = vec_adds(vp->old_metrics->v[i],metric);
