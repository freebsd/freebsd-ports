--- PDP11/pdp11_ke.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_ke.c
@@ -252,7 +252,7 @@ switch (PA & 017) {                     
         data = data & 077;                              /* 6b shift count */
         if (data != 0) {
             t32 = (ke_AC << 16) | ke_MQ;                /* 32b operand */
-            if (sign = GET_SIGN_W (ke_AC))              /* sext operand */
+            if ((sign = GET_SIGN_W (ke_AC)))            /* sext operand */
                 t32 = t32 | ~017777777777;
             if (data < 32) {                            /* [1,31] - left */
                 sout = (t32 >> (32 - data)) | (-sign << data);
@@ -282,7 +282,7 @@ switch (PA & 017) {                     
         data = data & 077;                              /* 6b shift count */
         if (data != 0) {
             t32 = (ke_AC << 16) | ke_MQ;                /* 32b operand */
-            if (sign = GET_SIGN_W (ke_AC))              /* sext operand */
+            if ((sign = GET_SIGN_W (ke_AC)))            /* sext operand */
                 t32 = t32 | ~017777777777;
             if (data < 32) {                            /* [1,31] - left */
                 sout = (t32 >> (31 - data)) | (-sign << data);
