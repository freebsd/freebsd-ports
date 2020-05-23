--- pglogical_apply_spi.c.orig	2019-03-06 06:44:31 UTC
+++ pglogical_apply_spi.c
@@ -16,6 +16,7 @@
  */
 #include <stdio.h>
 #include <unistd.h>
+#include <arpa/inet.h>
 
 #include "postgres.h"
 
