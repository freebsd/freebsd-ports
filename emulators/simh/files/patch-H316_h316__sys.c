--- H316/h316_sys.c.orig	2016-12-01 22:43:42 UTC
+++ H316/h316_sys.c
@@ -364,11 +364,11 @@ switch (j) {                            
 
     case I_V_MRF: case I_V_MRX:                         /* mem ref */
         cptr = get_glyph (cptr, gbuf, ',');             /* get next field */
-        if (k = (strcmp (gbuf, "C") == 0)) {            /* C specified? */
+        if ((k = (strcmp (gbuf, "C") == 0))) {          /* C specified? */
             val[0] = val[0] | SC;
             cptr = get_glyph (cptr, gbuf, 0);
             }
-        else if (k = (strcmp (gbuf, "Z") == 0)) {       /* Z specified? */
+        else if ((k = (strcmp (gbuf, "Z") == 0))) {     /* Z specified? */
             cptr = get_glyph (cptr, gbuf, ',');
             }
         d = get_uint (gbuf, 8, X_AMASK, &r);            /* construe as addr */
