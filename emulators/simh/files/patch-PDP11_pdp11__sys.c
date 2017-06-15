--- PDP11/pdp11_sys.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_sys.c
@@ -1071,7 +1071,8 @@ switch (j) {                            
         for (cptr = get_glyph (cptr, gbuf, 0); gbuf[0] != 0;
             cptr = get_glyph (cptr, gbuf, 0)) {
             for (i = 0; (opcode[i] != NULL) &&
-                (strcmp (opcode[i], gbuf) != 0) ; i++) ;
+                (strcmp (opcode[i], gbuf) != 0) ; i++)
+			;
              if ((((opc_val[i] >> I_V_CL) & I_M_CL) != j) ||
                 (opcode[i] == NULL))
                 return SCPE_ARG;
