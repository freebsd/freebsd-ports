--- I1620/i1620_sys.c.orig	2016-12-01 22:43:42 UTC
+++ I1620/i1620_sys.c
@@ -552,7 +552,7 @@ if (I_GETQP (opfl) != I_M_QNP) {        
 
 cptr = get_glyph (cptr, fptr = gbuf, ' ');              /* get flag field */
 last = -1;                                              /* none yet */
-while (t = *fptr++) {                                   /* loop through */
+while ((t = *fptr++)) {                                 /* loop through */
     if ((t < '0') || (t > '9'))                         /* must be digit */
         return SCPE_ARG;
     t = t - '0';                                        /* convert */
