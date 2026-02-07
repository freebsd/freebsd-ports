--- sumsq_av.c.orig	2019-02-05 19:36:10 UTC
+++ sumsq_av.c
@@ -8,6 +8,7 @@
  * May be used under the terms of the GNU Lesser General Public License (LGPL)
  */
 
+#include <altivec.h>
 #include "fec.h"
 
 unsigned long long sumsq_av(signed short *in,int cnt){
@@ -17,15 +18,15 @@ unsigned long long sumsq_av(signed short *in,int cnt){
   int pad;
   union { vector unsigned char cv; vector unsigned int iv; unsigned int w[4]; unsigned char c[16];} s;
 
-  carries = sums = (vector unsigned int)(0);
+  carries = sums = (vector unsigned int){0};
   if((pad = (int)in & 15)!=0){
     /* Load unaligned leading word */
-    x = vec_perm(vec_ld(0,in),(vector signed short)(0),vec_lvsl(0,in));
+    x = vec_perm(vec_ld(0,in),(vector signed short){0},vec_lvsl(0,in));
     if(cnt < 8){ /* Shift right to chop stuff beyond end of short block */
       s.c[15] = (8-cnt)<<4;
       x = vec_sro(x,s.cv);
     }
-    sums = (vector unsigned int)vec_msum(x,x,(vector signed int)(0));
+    sums = (vector unsigned int)vec_msum(x,x,(vector signed int){0});
     in += 8-pad/2;
     cnt -= 8-pad/2;
   }
@@ -36,7 +37,7 @@ unsigned long long sumsq_av(signed short *in,int cnt){
      * the earlier terms separately to handle the carries
      * The cast to unsigned is OK because squares are always positive
      */
-    s1 = (vector unsigned int)vec_msum(x,x,(vector signed int)(0));
+    s1 = (vector unsigned int)vec_msum(x,x,(vector signed int){0});
     carries = vec_add(carries,vec_addc(sums,s1));
     sums = vec_add(sums,s1);
     in += 8;
@@ -47,7 +48,7 @@ unsigned long long sumsq_av(signed short *in,int cnt){
     x = vec_ld(0,in);
     s.c[15] = (8-cnt)<<4;
     x = vec_sro(x,s.cv);
-    s1 = (vector unsigned int)vec_msum(x,x,(vector signed int)(0));
+    s1 = (vector unsigned int)vec_msum(x,x,(vector signed int){0});
     carries = vec_add(carries,vec_addc(sums,s1));
     sums = vec_add(sums,s1);
   }
