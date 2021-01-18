--- dobutsu.c.orig	2021-01-16 17:37:49 UTC
+++ dobutsu.c
@@ -31,8 +31,7 @@
 #include <string.h>
 #include <unistd.h>
 
-#include <readline/readline.h>
-#include <readline/history.h>
+#include <editline/readline.h>
 
 #include "rules.h"
 #include "tablebase.h"
