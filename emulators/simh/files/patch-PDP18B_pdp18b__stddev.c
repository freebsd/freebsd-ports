--- PDP18B/pdp18b_stddev.c.orig	2016-12-01 22:43:42 UTC
+++ PDP18B/pdp18b_stddev.c
@@ -594,7 +594,7 @@ if ((temp = getc (ptr_unit.fileref)) == 
 if (ptr_state == 0) {                                   /* ASCII */
     if (ptr_unit.flags & UNIT_RASCII) {                 /* want parity? */
         ptr_unit.buf = temp = temp & 0177;              /* parity off */
-        while (temp = temp & (temp - 1))
+        while ((temp = temp & (temp - 1)))
             ptr_unit.buf = ptr_unit.buf ^ 0200;         /* count bits */
         ptr_unit.buf = ptr_unit.buf ^ 0200;             /* set even parity */
         }
