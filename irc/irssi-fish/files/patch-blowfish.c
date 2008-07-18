--- blowfish.c.orig	2005-01-16 14:59:16.000000000 -0900
+++ blowfish.c	2008-07-14 21:46:38.000000000 -0800
@@ -1,4 +1,6 @@
 #include "blowfish.h"
+#include <string.h>
+#include <stdlib.h>
 
 /* #define S(x,i) (bf_S[i][x.w.byte##i]) */
 #define S0(x) (bf_S[0][x.w.byte0])
