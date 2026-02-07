--- viterbi27_av.c.orig	2019-02-05 19:34:45 UTC
+++ viterbi27_av.c
@@ -1,6 +1,7 @@
 /* K=7 r=1/2 Viterbi decoder for PowerPC G4/G5 Altivec instructions
  * Feb 2004, Phil Karn, KA9Q
  */
+#include <altivec.h>
 #include <stdio.h>
 #include <memory.h>
 #include <stdlib.h>
@@ -31,7 +32,7 @@ int init_viterbi27_av(void *p,int starting_state){
   if(p == NULL)
     return -1;
   for(i=0;i<4;i++)
-    vp->metrics1.v[i] = (vector unsigned char)(63);
+    vp->metrics1.v[i] = (vector unsigned char){63};
   vp->old_metrics = &vp->metrics1;
   vp->new_metrics = &vp->metrics2;
   vp->dp = vp->decisions;
@@ -134,8 +135,8 @@ int update_viterbi27_blk_av(void *p,unsigned char *sym
 
     /* Form first set of 16 branch metrics */
     metric = vec_avg(vec_xor(Branchtab27[0].v[0],sym0v),vec_xor(Branchtab27[1].v[0],sym1v));
-    metric = vec_sr(metric,(vector unsigned char)(3));
-    m_metric = vec_sub((vector unsigned char)(31),metric);
+    metric = vec_sr(metric,(vector unsigned char){3});
+    m_metric = vec_sub((vector unsigned char){31},metric);
     
     /* Form first set of path metrics */
     m0 = vec_adds(vp->old_metrics->v[0],metric);
@@ -145,8 +146,8 @@ int update_viterbi27_blk_av(void *p,unsigned char *sym
     
     /* Form second set of 16 branch metrics */
     metric = vec_avg(vec_xor(Branchtab27[0].v[1],sym0v),vec_xor(Branchtab27[1].v[1],sym1v));
-    metric = vec_sr(metric,(vector unsigned char)(3));
-    m_metric = vec_sub((vector unsigned char)(31),metric);
+    metric = vec_sr(metric,(vector unsigned char){3});
+    m_metric = vec_sub((vector unsigned char){31},metric);
 
     /* Compare and select first set */
     decision0 = vec_cmpgt(m0,m1);
