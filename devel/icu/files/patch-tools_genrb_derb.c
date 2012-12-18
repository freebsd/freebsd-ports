--- tools/genrb/derb.c.orig	2012-11-05 18:14:54.000000000 +0100
+++ tools/genrb/derb.c	2012-12-17 04:02:54.787359037 +0100
@@ -27,6 +27,7 @@
 #include "ustrfmt.h"
 
 #include <stdlib.h>
+#define _TRUNCATE_DECLARED
 #include <stdio.h>
 #include <ctype.h>
 
