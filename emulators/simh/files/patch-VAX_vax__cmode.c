--- VAX/vax_cmode.c.orig	2016-12-01 22:43:43 UTC
+++ VAX/vax_cmode.c
@@ -621,7 +621,7 @@ switch ((IR >> 12) & 017) {             
             else src2 = RdMemW (GeteaW (dstspec));
             src2 = src2 & 077;
             src = RdRegW (srcspec);                     /* get src */
-            if (sign = ((src & WSIGN)? 1: 0))
+            if ((sign = ((src & WSIGN)? 1: 0)))
                 src = src | ~WMASK;
             if (src2 == 0) {                            /* [0] */
                 dst = src;                              /* result */
