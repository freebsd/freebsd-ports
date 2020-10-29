--- src/rr.c.orig	2020-10-29 02:40:53 UTC
+++ src/rr.c
@@ -32,6 +32,8 @@
 #include <stdlib.h>
 #include <stdint.h>
 
+#include <netinet/in.h>
+
 #include "utils.h"
 #include "microdns/microdns.h"
 #include "microdns/rr.h"
