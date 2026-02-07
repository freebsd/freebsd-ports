--- src/mswstr.c.orig	2021-01-08 09:11:21 UTC
+++ src/mswstr.c
@@ -8,7 +8,7 @@
 
 #include <stdio.h>
 #include <assert.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 
 #include "nls.h"
