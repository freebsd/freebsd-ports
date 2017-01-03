--- LGP/lgp_sys.c.orig	2016-12-01 22:43:42 UTC
+++ LGP/lgp_sys.c
@@ -363,7 +363,7 @@ if ((sw & SWMASK ('L')) ||              
             return SCPE_OK;
         if (islower (c))
             c = toupper (c);
-        if (tptr = strchr (hex_decode, c))
+        if ((tptr = strchr (hex_decode, c)))
             val[0] = (val[0] << 4) | (tptr - hex_decode);
         else return SCPE_ARG;
         }
@@ -388,7 +388,7 @@ else sgn = 0;
 cptr = get_glyph (cptr, gbuf, 0);                       /* get opcode */
 if (gbuf[1] != 0)
     return SCPE_ARG;
-if (tptr = strchr (opcode, gbuf[0]))
+if ((tptr = strchr (opcode, gbuf[0])))
     val[0] = ((tptr - opcode) << I_V_OP) | sgn;         /* merge opcode */
 else return SCPE_ARG;
 cptr = get_glyph (cptr, gbuf, 0);                       /* get address */
