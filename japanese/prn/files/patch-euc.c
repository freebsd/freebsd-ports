--- euc.c.orig
+++ euc.c
@@ -26,6 +26,9 @@
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <ctype.h>
 #include "euc.h"
 
 #if defined EUC
