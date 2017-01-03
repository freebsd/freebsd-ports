--- PDP18B/pdp18b_sys.c.orig	2016-12-01 22:43:42 UTC
+++ PDP18B/pdp18b_sys.c
@@ -1009,7 +1009,7 @@ for (i = 0; opc_val[i] >= 0; i++) {     
             break;
 
         case I_V_OPR:                                   /* operate */
-            if (sp = (inst & 03730))
+            if ((sp = (inst & 03730)))
                 fprintf (of, "%s", opcode[i]);
             fprint_opr (of, inst & 014047, I_V_OPR, sp);
             break;
