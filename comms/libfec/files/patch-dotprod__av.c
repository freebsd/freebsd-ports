--- dotprod_av.c.orig	2019-02-05 19:37:00 UTC
+++ dotprod_av.c
@@ -3,6 +3,7 @@
  * Copyright 2004 Phil Karn
  * May be used under the terms of the GNU Lesser General Public License (LGPL)
  */
+#include <altivec.h>
 #include <stdlib.h>
 #include "fec.h"
 
@@ -70,7 +71,7 @@ long dotprod_av(void *p,signed short a[]){
   nblocks = (dp->len+al-1)/8+1;
   
   /* Sum into four vectors each holding four 32-bit partial sums */
-  sums3 = sums2 = sums1 = sums0 = (vector signed int)(0);
+  sums3 = sums2 = sums1 = sums0 = (vector signed int){0};
   while(nblocks >= 4){
     sums0 = vec_msums(ar[nblocks-1],d[nblocks-1],sums0);
     sums1 = vec_msums(ar[nblocks-2],d[nblocks-2],sums1);
@@ -85,7 +86,7 @@ long dotprod_av(void *p,signed short a[]){
     sums0 = vec_msums(ar[nblocks],d[nblocks],sums0);
   }
   /* Sum 4 partial sums into final result */
-  s.v = vec_sums(sums0,(vector signed int)(0));
+  s.v = vec_sums(sums0,(vector signed int){0});
   
   return s.w[3];
 }
