--- src/java.base/share/native/libfdlibm/e_asin.c.orig	2020-01-15 18:29:57 UTC
+++ src/java.base/share/native/libfdlibm/e_asin.c
@@ -97,12 +97,13 @@ qS4 =  7.70381505559019352791e-02; /* 0x3FB3B8C5, 0xB1
         } else if (ix<0x3fe00000) {     /* |x|<0.5 */
             if(ix<0x3e400000) {         /* if |x| < 2**-27 */
                 if(huge+x>one) return x;/* return x with inexact if x!=0*/
-            } else
+            } else {
                 t = x*x;
                 p = t*(pS0+t*(pS1+t*(pS2+t*(pS3+t*(pS4+t*pS5)))));
                 q = one+t*(qS1+t*(qS2+t*(qS3+t*qS4)));
                 w = p/q;
                 return x+x*w;
+            }
         }
         /* 1> |x|>= 0.5 */
         w = one-fabs(x);
