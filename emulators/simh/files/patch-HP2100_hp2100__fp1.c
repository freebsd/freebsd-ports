--- HP2100/hp2100_fp1.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_fp1.c
@@ -1145,12 +1145,12 @@ if (operand_l && operand_r) {           
         *operand_l = fp_a;                              /* first op is accum */
     }
 
-if (result)                                             /* want result precision? */
+if (result) {                                           /* want result precision? */
     if ((opcode & 0120) == 0100)                        /* fix? */
         *result = int_size;                             /* result is integer */
     else                                                /* all others */
         *result = fp_size;                              /* result is fp */
-
+}
 return;
 }
 
