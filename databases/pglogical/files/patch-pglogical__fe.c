--- pglogical_fe.c.orig	2021-06-06 20:18:17 UTC
+++ pglogical_fe.c
@@ -10,6 +10,8 @@
  *
  *-------------------------------------------------------------------------
  */
+#include "sys/wait.h"
+
 #include "libpq-fe.h"
 #include "postgres_fe.h"
 
