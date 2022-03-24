--- euc.c.orig	1994-03-28 10:21:54 UTC
+++ euc.c
@@ -26,6 +26,9 @@ static char *sccsid = "@(#)euc.c 2.2 (Y.
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <ctype.h>
 #include "euc.h"
 
 #if defined EUC
