--- postgres.c.orig	Sat Apr 21 19:16:37 2001
+++ postgres.c	Sat Apr 21 19:16:47 2001
@@ -18,7 +18,7 @@
 
 #include <libpq-fe.h>
 #include <string.h>
-#include <postgres.h>
+#include <c.h>
 
 #include "common.h"
 #include "status.h"
