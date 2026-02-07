--- HP2100/hp2100_sys.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_sys.c
@@ -608,11 +608,11 @@ if (opcode[i]) {                        
 
     case I_V_MRF:                                       /* mem ref */
         cptr = get_glyph (cptr, gbuf, 0);               /* get next field */
-        if (k = (strcmp (gbuf, "C") == 0)) {            /* C specified? */
+        if ((k = (strcmp (gbuf, "C") == 0))) {          /* C specified? */
             val[0] = val[0] | I_CP;
             cptr = get_glyph (cptr, gbuf, 0);
             }
-        else if (k = (strcmp (gbuf, "Z") == 0)) {       /* Z specified? */
+        else if ((k = (strcmp (gbuf, "Z") == 0))) {     /* Z specified? */
             cptr = get_glyph (cptr, gbuf, ',');
             }
         if ((d = get_addr (gbuf)) < 0) return SCPE_ARG;
