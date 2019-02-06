--- peakval_av.c.orig	2019-02-05 19:35:25 UTC
+++ peakval_av.c
@@ -6,6 +6,7 @@
  * May be used under the terms of the GNU Lesser General Public License (LGPL)
  */
 
+#include <altivec.h>
 #include "fec.h"
 
 signed short peakval_av(signed short *in,int cnt){
@@ -14,11 +15,11 @@ signed short peakval_av(signed short *in,int cnt){
   union { vector signed char cv; vector signed short hv; signed short s[8]; signed char c[16];} s;
   vector signed short smallest,largest;
 
-  smallest = (vector signed short)(0);
-  largest = (vector signed short)(0);
+  smallest = (vector signed short){0};
+  largest = (vector signed short){0};
   if((pad = (int)in & 15)!=0){
     /* Load unaligned leading word */
-    x = vec_perm(vec_ld(0,in),(vector signed short)(0),vec_lvsl(0,in));
+    x = vec_perm(vec_ld(0,in),(vector signed short){0},vec_lvsl(0,in));
     if(cnt < 8){ /* Shift right to chop stuff beyond end of short block */
       s.c[15] = (8-cnt)<<4;
       x = vec_sro(x,s.cv);
