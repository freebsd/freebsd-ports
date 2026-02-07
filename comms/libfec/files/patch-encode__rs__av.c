--- encode_rs_av.c.orig	2019-02-05 19:29:53 UTC
+++ encode_rs_av.c
@@ -2,6 +2,7 @@
  * Copyright 2004, Phil Karn KA9Q
  * May be used under the terms of the GNU Lesser General Public License (LGPL)
  */
+#include <altivec.h>
 #include <stdio.h>
 #include <string.h>
 #include "fixed.h"
@@ -12,8 +13,8 @@
  */
 static union { vector unsigned char v; unsigned char c[16]; } table[256];
 
-static vector unsigned char reverse = (vector unsigned char)(0,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1);
-static vector unsigned char shift_right = (vector unsigned char)(15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30);
+static vector unsigned char reverse = (vector unsigned char){0,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
+static vector unsigned char shift_right = (vector unsigned char){15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
 
 extern data_t CCSDS_alpha_to[];
 extern data_t CCSDS_index_of[];
@@ -40,8 +41,8 @@ void encode_rs_av(unsigned char *data,unsigned char *p
   union { vector unsigned char v[2]; unsigned char c[32]; } shift_register;
   int i;
 
-  shift_register.v[0] = (vector unsigned char)(0);
-  shift_register.v[1] = (vector unsigned char)(0);
+  shift_register.v[0] = (vector unsigned char){0};
+  shift_register.v[1] = (vector unsigned char){0};
   
   for(i=0;i<NN-NROOTS-pad;i++){
     vector unsigned char feedback0,feedback1;
@@ -53,7 +54,7 @@ void encode_rs_av(unsigned char *data,unsigned char *p
 
     /* Shift right one byte */
     shift_register.v[1] = vec_perm(shift_register.v[0],shift_register.v[1],shift_right) ^ feedback1;
-    shift_register.v[0] = vec_sro(shift_register.v[0],(vector unsigned char)(8)) ^ feedback0;
+    shift_register.v[0] = vec_sro(shift_register.v[0],(vector unsigned char){8}) ^ feedback0;
     shift_register.c[0] = f;
   }
   for(i=0;i<NROOTS;i++)
