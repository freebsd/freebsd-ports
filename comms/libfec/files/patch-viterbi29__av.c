--- viterbi29_av.c.orig	2019-02-05 19:33:58 UTC
+++ viterbi29_av.c
@@ -2,9 +2,11 @@
  * Copyright Feb 2004, Phil Karn, KA9Q
  * May be used under the terms of the GNU Lesser General Public License (LGPL)
  */
+#include <altivec.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <memory.h>
+#include <sys/types.h>
 #include <sys/sysctl.h>
 #include "fec.h"
 
@@ -31,7 +33,7 @@ int init_viterbi29_av(void *p,int starting_state){
   if(p == NULL)
     return -1;
   for(i=0;i<16;i++)
-    vp->metrics1.v[i] = (vector unsigned char)(63);
+    vp->metrics1.v[i] = (vector unsigned char){63};
 
   vp->old_metrics = &vp->metrics1;
   vp->new_metrics = &vp->metrics2;
@@ -136,8 +138,8 @@ int update_viterbi29_blk_av(void *p,unsigned char *sym
 
       /* Form branch metrics */
       metric = vec_avg(vec_xor(Branchtab29[0].v[i],sym1v),vec_xor(Branchtab29[1].v[i],sym2v));
-      metric = vec_sr(metric,(vector unsigned char)(3));
-      m_metric = (vector unsigned char)(31) - metric;
+      metric = vec_sr(metric,(vector unsigned char){3});
+      m_metric = (vector unsigned char){31} - metric;
     
       /* Add branch metrics to path metrics */
       m0 = vec_adds(vp->old_metrics->v[i],metric);
