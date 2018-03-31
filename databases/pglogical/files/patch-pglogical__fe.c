--- pglogical_fe.c.orig	2018-03-17 09:48:56 UTC
+++ pglogical_fe.c
@@ -10,6 +10,8 @@
  *
  *-------------------------------------------------------------------------
  */
+#include <sys/wait.h>
+
 #include "postgres_fe.h"
 
 #include "pglogical_fe.h"
