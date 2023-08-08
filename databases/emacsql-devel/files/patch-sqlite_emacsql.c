--- sqlite/emacsql.c.orig	2020-07-14 00:28:59 UTC
+++ sqlite/emacsql.c
@@ -1,7 +1,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include "sqlite3.h"
+#include <sqlite3.h>
 
 #define TRUE 1
 #define FALSE 0
