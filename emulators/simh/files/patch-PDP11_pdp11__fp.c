--- PDP11/pdp11_fp.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_fp.c
@@ -438,7 +438,7 @@ switch ((IR >> 8) & 017) {              
         else fac.l = ReadI (GeteaFP (dstspec, leni), dstspec, leni);
         fac.h = 0;
         if (fac.l) {
-            if (sign = GET_SIGN_L (fac.l))
+            if ((sign = GET_SIGN_L (fac.l)))
                 fac.l = (fac.l ^ 0xFFFFFFFF) + 1;
             for (i = 0; GET_SIGN_L (fac.l) == 0; i++)
                 fac.l = fac.l << 1;
